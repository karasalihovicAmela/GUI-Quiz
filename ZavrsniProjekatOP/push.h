#ifndef PUSH_H
#define PUSH_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "database.h"

namespace Ui {
class Push;
}

class Push : public QDialog
{
    Q_OBJECT

public:
    explicit Push(QString kid, QString pid, QWidget *parent = nullptr);
    ~Push();
    void openDatabase();
    void setQuestion();
    void setAnswer();
    void checkAnswer();
    void checkChoosen();
    void addPoints();

signals:
    void answered(QString);

private slots:
    void on_odg1_clicked();

    void on_odgovori_clicked();

    void on_odg2_clicked();

    void on_odg3_clicked();

    void on_odg4_clicked();

    void on_odg5_clicked();

private:
    Ui::Push *ui;
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

#endif // PUSH_H
