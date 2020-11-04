#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql/QSql>
#include "database.h"
#include "login.h"
#include "radio.h"
#include "check.h"
#include "combo.h"
#include "push.h"
#include "pregled.h"
#include <QDate>
#include <QImage>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString trenutniID;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void pitanjadisabled();
    void Start();
    void Status();
    void Date();
    int getPoints();
    void setPoints(int*);
    void pointsZero();

public slots:
    void pitanjaenabled();
    void odgovoreni(QString);

private slots:
    void on_actionLog_In_triggered();

    void on_actionLog_in_triggered();

    void on_Pitanje_1_clicked();

    void on_Pitanje_2_clicked();

    void on_Pitanje_3_clicked();

    void on_Pitanje_4_clicked();

    void on_Pitanje_5_clicked();

    void on_Pitanje_6_clicked();

    void on_Pitanje_7_clicked();

    void on_Pitanje_8_clicked();

    void on_Pitanje_9_clicked();

    void on_Pitanje_10_clicked();

    void on_Pitanje_11_clicked();

    void on_Pitanje_12_clicked();

    void on_Pitanje_13_clicked();

    void on_Pitanje_14_clicked();

    void on_Pitanje_15_clicked();

    void on_Pitanje_16_clicked();

    void on_Pitanje_17_clicked();

    void on_Pitanje_18_clicked();

    void on_Pitanje_19_clicked();

    void on_Pitanje_20_clicked();

    void on_Pitanje_21_clicked();

    void on_Pitanje_22_clicked();

    void on_Pitanje_23_clicked();

    void on_Pitanje_24_clicked();

    void on_Pitanje_25_clicked();

    void on_zavrsi_clicked();

    void on_actionPregled_triggered();

    void on_actionPregled_2_triggered();

    void on_zatvori_clicked();

private:
    Ui::MainWindow *ui;
    Database *mydb;
    login *log;
    void update(QString);
    Radio *radio;
    Check *check;
    Combo *combo;
    Push *push;
    int *Bodovi;
    Pregled *view;

};
#endif // MAINWINDOW_H
