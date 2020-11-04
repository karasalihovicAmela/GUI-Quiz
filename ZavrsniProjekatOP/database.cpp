#include "database.h"

Database::Database()
{
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Amela/Downloads/Objektno programiranje/Projekat OP/KVIZ.db");

    if(!mydb.open())
        qDebug() <<"Bazu podataka nije moguce otvoriti!";

    else
        qDebug() <<"Baza je otvorena!";


}

bool Database::otvoreno()
{
    if(mydb.open())
        return true;
    else
        return false;
}
