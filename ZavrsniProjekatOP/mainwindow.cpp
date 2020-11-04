#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->zavrsi->setStyleSheet("background-color:#C4A9E6; color:#ffffff;");
    ui->zatvori->setStyleSheet("background-color:#CC2E2E; color:#ffffff;");

    this->resize(800,600);

    Start();

    pitanjadisabled();

    log = new login(this);
    connect(log,SIGNAL(loginuspjesan(QString)),this,SLOT(pitanjaenabled()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pitanjadisabled()
{
    //prilikom pokretanja programa push button-i su isključeni
    ui->Pitanje_1->setEnabled(false);
    ui->Pitanje_2->setEnabled(false);
    ui->Pitanje_3->setEnabled(false);
    ui->Pitanje_4->setEnabled(false);
    ui->Pitanje_5->setEnabled(false);
    ui->Pitanje_6->setEnabled(false);
    ui->Pitanje_7->setEnabled(false);
    ui->Pitanje_8->setEnabled(false);
    ui->Pitanje_9->setEnabled(false);
    ui->Pitanje_10->setEnabled(false);
    ui->Pitanje_11->setEnabled(false);
    ui->Pitanje_12->setEnabled(false);
    ui->Pitanje_13->setEnabled(false);
    ui->Pitanje_14->setEnabled(false);
    ui->Pitanje_15->setEnabled(false);
    ui->Pitanje_16->setEnabled(false);
    ui->Pitanje_17->setEnabled(false);
    ui->Pitanje_18->setEnabled(false);
    ui->Pitanje_19->setEnabled(false);
    ui->Pitanje_20->setEnabled(false);
    ui->Pitanje_21->setEnabled(false);
    ui->Pitanje_22->setEnabled(false);
    ui->Pitanje_23->setEnabled(false);
    ui->Pitanje_24->setEnabled(false);
    ui->Pitanje_25->setEnabled(false);

}

void MainWindow::Start()
{
    ui->progressBar->setValue(1);
    ui->progressBar->setVisible(false);
    ui->progressBar->setMaximum(25);

    mydb = new Database();
    if(mydb->otvoreno()== true){
        ui->baza->setText("Baza je otvorena!");
    }
    else
        ui->baza->setText("Bazu nije moguce otvoriti!");

}

void MainWindow::pitanjaenabled()
{
    //nakon prijavljivanja button-i za pitanja se ukljucuju
    log->hide();
    ui->Pitanje_1->setEnabled(true);
    ui->Pitanje_1->setStyleSheet("background-color: #7FB0EF; color:#ffffff;");
    ui->Pitanje_2->setEnabled(true);
    ui->Pitanje_2->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_3->setEnabled(true);
    ui->Pitanje_3->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_4->setEnabled(true);
    ui->Pitanje_4->setStyleSheet("background-color: #55E889; color:#ffffff;");
    ui->Pitanje_5->setEnabled(true);
    ui->Pitanje_5->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->Pitanje_6->setEnabled(true);
    ui->Pitanje_6->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_7->setEnabled(true);
    ui->Pitanje_7->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->Pitanje_8->setEnabled(true);
    ui->Pitanje_8->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_9->setEnabled(true);
    ui->Pitanje_9->setStyleSheet("background-color: #7FB0EF; color:#ffffff;");
    ui->Pitanje_10->setEnabled(true);
    ui->Pitanje_10->setStyleSheet("background-color: #55E889; color:#ffffff;");
    ui->Pitanje_11->setEnabled(true);
    ui->Pitanje_11->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->Pitanje_12->setEnabled(true);
    ui->Pitanje_12->setStyleSheet("background-color: #7FB0EF; color:#ffffff;");
    ui->Pitanje_13->setEnabled(true);
    ui->Pitanje_13->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_14->setEnabled(true);
    ui->Pitanje_14->setStyleSheet("background-color: #55E889; color:#ffffff;");
    ui->Pitanje_15->setEnabled(true);
    ui->Pitanje_15->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_16->setEnabled(true);
    ui->Pitanje_16->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->Pitanje_17->setEnabled(true);
    ui->Pitanje_17->setStyleSheet("background-color: #7FB0EF; color:#ffffff;");
    ui->Pitanje_18->setEnabled(true);
    ui->Pitanje_18->setStyleSheet("background-color: #55E889; color:#ffffff;");
    ui->Pitanje_19->setEnabled(true);
    ui->Pitanje_19->setStyleSheet("background-color: #F40B2E; color:#ffffff;");
    ui->Pitanje_20->setEnabled(true);
    ui->Pitanje_20->setStyleSheet("background-color: #7FB0EF; color:#ffffff;");
    ui->Pitanje_21->setEnabled(true);
    ui->Pitanje_21->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_22->setEnabled(true);
    ui->Pitanje_22->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_23->setEnabled(true);
    ui->Pitanje_23->setStyleSheet("background-color: #EF937F; color:#ffffff;");
    ui->Pitanje_24->setEnabled(true);
    ui->Pitanje_24->setStyleSheet("background-color: #55E889; color:#ffffff;");
    ui->Pitanje_25->setEnabled(true);
    ui->Pitanje_25->setStyleSheet("background-color: #EF937F; color:#ffffff;");

    //upisivanje studenta u status bar
    mydb = new Database;
    QSqlQuery qry;
    QString korisnicko = log->korisnicko;
    qry.prepare("SELECT Redni_broj FROM STUDENTI WHERE Korisnicko_ime='" + korisnicko+"'");
    qry.exec();
    qry.next();
    QString id = qry.value(0).toString();
    update(id);
    trenutniID = id;
    log->close();

    pointsZero();

    ui->progressBar->setVisible(true);
    Status();

}

void MainWindow::update(QString id)
{
   QSqlQuery qry;

   qry.prepare("SELECT Ime, Prezime FROM STUDENTI WHERE Redni_broj='"+id+"' ");
   qry.exec();
   qry.next();
   QString ime = qry.value(0).toString();
   ui->baza->setText(qry.value(0).toString() + " " + qry.value(1).toString());
}

void MainWindow::odgovoreni(QString odg)
{
    if(odg == "1")
        ui->Pitanje_1->setEnabled(false);

    else if(odg == "2")
        ui->Pitanje_2->setEnabled(false);

    else if(odg == "3")
        ui->Pitanje_3->setEnabled(false);

    else if (odg == "4")
        ui->Pitanje_4->setEnabled(false);

    else if (odg == "5")
        ui->Pitanje_5->setEnabled(false);

    else if (odg == "6")
        ui->Pitanje_6->setEnabled(false);

    else if (odg == "7")
        ui->Pitanje_7->setEnabled(false);

    else if (odg == "8")
        ui->Pitanje_8->setEnabled(false);

    else if (odg == "9")
        ui->Pitanje_9->setEnabled(false);

    else if (odg == "10")
        ui->Pitanje_10->setEnabled(false);

    else if (odg == "11")
        ui->Pitanje_11->setEnabled(false);

    else if (odg == "12")
        ui->Pitanje_12->setEnabled(false);

    else if (odg == "13")
        ui->Pitanje_13->setEnabled(false);

    else if (odg == "14")
        ui->Pitanje_14->setEnabled(false);

    else if (odg == "15")
        ui->Pitanje_15->setEnabled(false);

    else if (odg == "16")
        ui->Pitanje_16->setEnabled(false);

    else if (odg == "17")
        ui->Pitanje_17->setEnabled(false);

    else if (odg == "18")
        ui->Pitanje_18->setEnabled(false);

    else if (odg == "19")
        ui->Pitanje_19->setEnabled(false);

    else if (odg == "20")
        ui->Pitanje_20->setEnabled(false);

    else if (odg == "21")
        ui->Pitanje_21->setEnabled(false);

    else if (odg == "22")
        ui->Pitanje_22->setEnabled(false);

    else if (odg == "23")
        ui->Pitanje_23->setEnabled(false);

    else if (odg == "24")
        ui->Pitanje_24->setEnabled(false);

    else if (odg == "25")
        ui->Pitanje_25->setEnabled(false);

}


void MainWindow::on_actionLog_In_triggered()
{
    log->exec();
}

void MainWindow::on_actionLog_in_triggered()
{
    log->exec();
}

void MainWindow::on_Pitanje_1_clicked()
{
    radio = new Radio(trenutniID, "1");
    connect(radio,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    radio->exec();
    Status();
}

void MainWindow::on_Pitanje_2_clicked()
{
    check = new Check(trenutniID, "2");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_3_clicked()
{
    check = new Check(trenutniID, "3");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_4_clicked()
{
    combo = new Combo(trenutniID, "4");
    connect(combo,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    combo->exec();
    Status();
}

void MainWindow::on_Pitanje_5_clicked()
{
    push = new Push(trenutniID, "5");
    connect(push,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    push->exec();
    Status();
}

void MainWindow::on_Pitanje_6_clicked()
{
    check = new Check(trenutniID, "6");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_7_clicked()
{
    push = new Push(trenutniID, "7");
    connect(push,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    push->exec();
    Status();
}

void MainWindow::on_Pitanje_8_clicked()
{
    check = new Check(trenutniID, "8");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_9_clicked()
{
    radio = new Radio(trenutniID, "9");
    connect(radio,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    radio->exec();
    Status();
}

void MainWindow::on_Pitanje_10_clicked()
{
    combo = new Combo(trenutniID, "10");
    connect(combo,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    combo->exec();
    Status();
}

void MainWindow::on_Pitanje_11_clicked()
{
    push = new Push(trenutniID, "11");
    connect(push,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    push->exec();
    Status();
}

void MainWindow::on_Pitanje_12_clicked()
{
    radio = new Radio(trenutniID, "12");
    connect(radio,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    radio->exec();
    Status();
}

void MainWindow::on_Pitanje_13_clicked()
{
    check = new Check(trenutniID, "13");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_14_clicked()
{
    combo = new Combo(trenutniID, "14");
    connect(combo,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    combo->exec();
    Status();
}

void MainWindow::on_Pitanje_15_clicked()
{
    check = new Check(trenutniID, "15");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_16_clicked()
{
    push = new Push(trenutniID, "16");
    connect(push,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    push->exec();
    Status();
}

void MainWindow::on_Pitanje_17_clicked()
{
    radio = new Radio(trenutniID, "17");
    connect(radio,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    radio->exec();
    Status();
}

void MainWindow::on_Pitanje_18_clicked()
{
    combo = new Combo(trenutniID, "18");
    connect(combo,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    combo->exec();
    Status();
}

void MainWindow::on_Pitanje_19_clicked()
{
    push = new Push(trenutniID, "19");
    connect(push,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    push->exec();
    Status();
}

void MainWindow::on_Pitanje_20_clicked()
{
    radio = new Radio(trenutniID, "20");
    connect(radio,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    radio->exec();
    Status();
}

void MainWindow::on_Pitanje_21_clicked()
{
    check = new Check(trenutniID, "21");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_22_clicked()
{
    check = new Check(trenutniID, "22");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_23_clicked()
{
    check = new Check(trenutniID, "23");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::on_Pitanje_24_clicked()
{
    combo = new Combo(trenutniID, "24");
    connect(combo,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    combo->exec();
    Status();
}

void MainWindow::on_Pitanje_25_clicked()
{
    check = new Check(trenutniID, "25");
    connect(check,SIGNAL(answered(QString)),this,SLOT(odgovoreni(QString)));
    check->exec();
    Status();
}

void MainWindow::Status()
{
    QSqlQuery qry;
    qry.prepare("SELECT Bodovi FROM STUDENTI WHERE Redni_broj='"+trenutniID+"' ");
    qry.exec();
    qry.next();

    Bodovi = new int (qry.value(0).toInt());
    ui->progressBar->setValue(*Bodovi);
}

void MainWindow::Date()
{
    QString* date = new QString();
    *date = QDate::currentDate().toString();

    QSqlQuery qry;
    qry.prepare("UPDATE STUDENTI SET Datum=:value WHERE Redni_broj='"+trenutniID+"' ");
    qry.bindValue(":value", *date);
    qry.exec();
}

int MainWindow::getPoints()
{
    return *Bodovi;
}

void MainWindow::setPoints(int *value)
{
    Bodovi = value;
}

void MainWindow::pointsZero()
{

    QSqlQuery qry;

    qry.prepare("UPDATE STUDENTI SET Bodovi=0 WHERE Redni_broj='"+trenutniID+"' ");

    qry.exec();

}


void MainWindow::on_zavrsi_clicked()
{
    Date();
    pitanjadisabled();
}

void MainWindow::on_actionPregled_triggered()
{
    view = new Pregled();
    view->exec();
}

void MainWindow::on_actionPregled_2_triggered()
{
    view = new Pregled();
    view->exec();
}

void MainWindow::on_zatvori_clicked()
{
    this->close();
}
