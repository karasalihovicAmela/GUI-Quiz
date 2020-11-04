#ifndef COMBO_H
#define COMBO_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include "database.h"

namespace Ui {
class Combo;
}

class Combo : public QDialog
{
    Q_OBJECT

public:
    explicit Combo(QString id, QString qid, QWidget *parent = nullptr);
    ~Combo();
    void openDatabase();
    void setQuestion();
    void setAnswer();
    void checkChoosen();
    void addPoints();

signals:
    void answered(QString);

private slots:
    void on_odgovori_clicked();

private:
    Ui::Combo *ui;
    Database *mydb;
    QSqlDatabase *baza;
    QString pID;
    QString kID;
    bool rezultat;
};

#endif // COMBO_H
