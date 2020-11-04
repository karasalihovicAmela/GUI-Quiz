#ifndef BODOVI_H
#define BODOVI_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include "database.h"


class Bodovi
{
public:
    void setZero();
    void setPoints(int);

    Bodovi();
    void getPoints(QString id);
    int points;
    Database *base;
};

#endif // BODOVI_H
