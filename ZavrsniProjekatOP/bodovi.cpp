#include "bodovi.h"

void Bodovi::setZero()
{
    points = 0;

}

void Bodovi::setPoints(int bdvi)
{
    points = bdvi;
}

Bodovi::Bodovi()
{

}

void Bodovi::getPoints(QString id)
{
    base = new Database;

    QSqlQuery qry;
    qry.prepare("UPDATE STUDENTI SET Bodovi=:value WHERE Redni_broj='"+id+"'");
    qry.bindValue(":value", points);
    qry.exec();

}
