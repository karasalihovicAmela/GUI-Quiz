#ifndef DATABASE_H
#define DATABASE_H
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>


class Database
{
public:
    Database();
    QSqlDatabase mydb;

    bool otvoreno();
};

#endif // DATABASE_H
