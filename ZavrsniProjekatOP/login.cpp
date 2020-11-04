#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->prijava->setStyleSheet("background-color: black; color: white;");
}

login::~login()
{
    delete ui;
}



void login::on_prijava_clicked()
{
    mydb = new Database;

    korisnicko = ui->lineEdit_korisnicko ->text();
    password = ui->lineEdit_password->text();

    QSqlQuery qry;

    if(qry.exec("SELECT * FROM STUDENTI WHERE Korisnicko_ime='"+korisnicko+"' AND Sifra='"+password+"' ")) {
        int count=0;
        while(qry.next()) {
            count++;
        }
        if(count>0) {
            qry.prepare("SELECT Redni_broj FROM STUDENTI WHERE Korisnicko_ime='"+korisnicko+"' ");
            qry.exec();
            qry.next();
            QString id = qry.value(0).toString();
            ui->label_student->setText("Login uspješan.");
            QMessageBox::information(this,"Uspjesno","Uspjesno ste se prijavili",QMessageBox::Ok);
            emit loginuspjesan(id);
        }
        else {

            ui->label_student->setText("Pogresno korisnicko ime ili password.");
            QMessageBox::information(this,"Greska","Pogresno korisnicko ime ili password",QMessageBox::Ok);
    }}
}
