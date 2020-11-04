#include "combo.h"
#include "ui_combo.h"

Combo::Combo(QString kid, QString pid, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Combo)
{
    ui->setupUi(this);
    ui->odgovori->setStyleSheet("background-color: #55E889; color:#ffffff;");
    pID = pid;
    kID = kid;
    setQuestion();
    setAnswer();
}

Combo::~Combo()
{
    delete ui;
}

void Combo::openDatabase()
{
    mydb = new Database();
}

void Combo::setQuestion()
{
    QSqlQuery qry;
    qry.prepare("SELECT Tekst_pitanja FROM PITANJA WHERE Redni_broj = '" +pID+"'");
    qry.exec();
    qry.next();
    ui->pitanje->setText(qry.value(0).toString());

}

void Combo::setAnswer()
{
    QSqlQuery qry;
    qry.prepare("SELECT Odgovor1, Odgovor2, Odgovor3, Odgovor4, Odgovor5 FROM PITANJA WHERE Redni_broj='"+pID+"' ");
    qry.exec();
    qry.next();
    ui->odgovori_2->addItem(qry.value(0).toString());
    ui->odgovori_2->addItem(qry.value(1).toString());
    ui->odgovori_2->addItem(qry.value(2).toString());
    ui->odgovori_2->addItem(qry.value(3).toString());
    ui->odgovori_2->addItem(qry.value(4).toString());
    ui->odgovori_2->setStyleSheet("background-color: #55E889; color:#ffffff;");
}

void Combo::checkChoosen()
{
    QSqlQuery qry;
    qry.prepare("SELECT Tacan1 FROM PITANJA WHERE Redni_broj='"+pID+"' ");
    qry.exec();
    qry.next();

    if(ui->odgovori_2->currentText() == qry.value(0).toString()) rezultat = true;
    else rezultat = false;
}

void Combo::addPoints()
{
    QSqlQuery qry;
    qry.prepare("SELECT Bodovi FROM STUDENTI WHERE Redni_broj='"+kID+"' ");
    qry.exec();
    qry.next();

    int points = qry.value(0).toInt();

    if(rezultat == true) points++;

    qry.prepare("UPDATE STUDENTI SET Bodovi=:value WHERE Redni_broj='"+kID+"' ");
    qry.bindValue(":value", points);
    qry.exec();

}

void Combo::on_odgovori_clicked()
{
    checkChoosen();
    addPoints();
    emit answered(pID);
    this->close();
}
