#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "database.h"

namespace Ui {
class Check;
}

class Check : public QDialog
{
    Q_OBJECT

public:
    explicit Check(QString kid, QString pid, QWidget *parent = nullptr);
    ~Check();
    void openDatabase();
    void setQuestion();
    void setAnswer();
    void checkAnswer();
    void checkChoosen();
    void addPoints();

signals:
    void answered(QString);

private slots:
    void on_odgovori_clicked();

private:
    Ui::Check *ui;
    Database *mydb;
    QSqlDatabase *baza;
    QString pID;
    QString kID;
    bool od1;
    bool od2;
    bool od3;
    bool od4;
    bool od5;
    bool rezultat;
};

#endif // CHECK_H
