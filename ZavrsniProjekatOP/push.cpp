#include "push.h"
#include "ui_push.h"

Push::Push(QString kid, QString pid, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Push)
{
    ui->setupUi(this);
    ui->odgovori->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    pID = pid;
    kID = kid;
    setQuestion();
    setAnswer();

    od1 = false;
    od2 = false;
    od3 = false;
    od4 = false;
    od5 = false;

    checkAnswer();
}

Push::~Push()
{
    delete ui;
}

void Push::openDatabase()
{
    mydb = new Database();
}

void Push::setQuestion()
{
    QSqlQuery qry;
    qry.prepare("SELECT Tekst_pitanja FROM PITANJA WHERE Redni_broj = '" +pID+"'");
    qry.exec();
    qry.next();
    ui->pitanje->setText(qry.value(0).toString());

}

void Push::setAnswer()
{
    QSqlQuery qry;
    qry.prepare("SELECT Odgovor1, Odgovor2, Odgovor3, Odgovor4, Odgovor5 FROM PITANJA WHERE Redni_broj = '" +pID+"'");
    qry.exec();
    qry.next();
    ui->odg1->setText(qry.value(0).toString());
    ui->odg1->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->odg2->setText(qry.value(1).toString());
    ui->odg2->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->odg3->setText(qry.value(2).toString());
    ui->odg3->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->odg4->setText(qry.value(3).toString());
    ui->odg4->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->odg5->setText(qry.value(4).toString());
    ui->odg5->setStyleSheet("background-color: #F40B2E; color:#ffffff;");

}

void Push::checkAnswer()
{
    QSqlQuery qry;
    qry.prepare("SELECT Tacan1 FROM PITANJA WHERE Redni_broj='"+pID+"' ");
    qry.exec();
    qry.next();

    if(ui->odg1->text() == qry.value(0).toString()) od1 = true;
    if(ui->odg2->text() == qry.value(0).toString()) od2 = true;
    if(ui->odg3->text() == qry.value(0).toString()) od3 = true;
    if(ui->odg4->text() == qry.value(0).toString()) od4 = true;
    if(ui->odg5->text() == qry.value(0).toString()) od5 = true;
}

void Push::checkChoosen()
{
    rezultat = false;

    if(ui->odg1->isChecked()){
        if(od1 == true) rezultat = true;
        else rezultat = false;
    }

    if(ui->odg2->isChecked()){
        if(od2 == true) rezultat = true;
        else rezultat = false;
    }

    if(ui->odg3->isChecked()){
        if(od3 == true) rezultat = true;
        else rezultat = false;
    }

    if(ui->odg4->isChecked()){
        if(od4 == true) rezultat = true;
        else rezultat = false;
    }

    if(ui->odg5->isChecked()){
        if(od5 == true) rezultat = true;
        else rezultat = false;
    }
}

void Push::addPoints()
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

void Push::on_odgovori_clicked()
{
    addPoints();
    emit answered(pID);
    this->close();
}

void Push::on_odg1_clicked()
{
    if (od1 == true) rezultat = true;
    else rezultat = false;

    on_odgovori_clicked();

}

void Push::on_odg2_clicked()
{
    if (od2 == true) rezultat = true;
    else rezultat = false;

    on_odgovori_clicked();
}

void Push::on_odg3_clicked()
{
    if (od3 == true) rezultat = true;
    else rezultat = false;

    on_odgovori_clicked();

}

void Push::on_odg4_clicked()
{
    if (od4 == true) rezultat = true;
    else rezultat = false;

    on_odgovori_clicked();
}

void Push::on_odg5_clicked()
{
    if (od5 == true) rezultat = true;
    else rezultat = false;

    on_odgovori_clicked();
}
