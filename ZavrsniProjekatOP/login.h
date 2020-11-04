#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    QString korisnicko;
    QString password;
    QSqlDatabase *base;
    Database *mydb;

    explicit login(QWidget *parent = nullptr);
    ~login();

signals:
    void loginuspjesan(QString);

private slots:
    void on_prijava_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
