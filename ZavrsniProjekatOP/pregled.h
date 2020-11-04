#ifndef PREGLED_H
#define PREGLED_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "database.h"

namespace Ui {
class Pregled;
}

class Pregled : public QDialog
{
    Q_OBJECT

public:
    explicit Pregled(QWidget *parent = nullptr);
    ~Pregled();
    void setData();

private:
    Ui::Pregled *ui;
    Database *mydb;
    QSqlQueryModel *model;
};

#endif // PREGLED_H
