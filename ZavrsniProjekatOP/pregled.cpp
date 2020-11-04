#include "pregled.h"
#include "ui_pregled.h"

Pregled::Pregled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pregled)
{
    ui->setupUi(this);
    ui->pregled->setStyleSheet("background:#EDC7C7;");
    mydb = new Database();
    setData();
}

Pregled::~Pregled()
{
    delete ui;
}

void Pregled::setData()
{
    QSqlQuery qry;
    qry.prepare("SELECT Ime, Prezime, Bodovi, Datum FROM STUDENTI");
    qry.exec();

    model = new QSqlQueryModel();
    model->setQuery(qry);
    ui->pregled->setModel(model);
}
