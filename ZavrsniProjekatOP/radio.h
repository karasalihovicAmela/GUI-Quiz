#ifndef RADIO_H
#define RADIO_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "database.h"

namespace Ui {
class Radio;
}

class Radio : public QDialog
{
    Q_OBJECT

public:
    explicit Radio(QString kid, QString pid, QWidget *parent = nullptr);
    ~Radio();
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
    Ui::Radio *ui;
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

#endif // RADIO_H
