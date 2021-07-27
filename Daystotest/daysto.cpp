#include "daysto.h"
#include "ui_daysto.h"
#include <QDate>
#include <QMessageBox>
daysto::daysto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::daysto)
{
    ui->setupUi(this);

    tmr = new QTimer(this); tmr->setInterval(60000);
   connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();

}

daysto::~daysto()
{
    delete ui;
    delete tmr;

}

void daysto::on_pushButton_clicked()
{
    QString str=ui->dateTimeEdit->text();
    QDate date=QDate::fromString(str,"dd.MM.yyyy");
    QDate tdate=QDate::currentDate();
    int d=date.daysTo(tdate);
    int yil=d/365;
    d=d%365-yil%4;
    int oy=d/30;
    d=d%30;
    QString input="Siz tug'ilgan kuningizdan hozirgacha "
            +QString::number(yil)+" Yil "
            +QString::number(oy)+ " oy "
            +QString::number(d)+" kun o'tgan";
    QMessageBox::information(this, tr("Hozirgi sana"),
                         input,
                         QMessageBox::Ok | QMessageBox::Cancel);

   /* int yil=tdate.year()-date.year();*/
}

void daysto::on_pushButton_2_clicked()
{
    QString str=ui->dateTimeEdit_2->text();
    QDate date=QDate::fromString(str,"dd.MM.yyyy");
    QDate tdate=QDate::currentDate();
    int d=tdate.daysTo(date);
    QString input="Bugundan bayramgacha "
            +QString::number(d)+" kun qolgan ";
    QMessageBox::information(this, tr("Bayram"),
                         input,
                         QMessageBox::Ok | QMessageBox::Cancel);
}
void daysto::updateTime()
{
                      QMessageBox::information(this, tr("Esanov Otabek"),
                                           "Esanov Otabek tomonidan ishlab chiqilgan",
                                           QMessageBox::Ok | QMessageBox::Cancel);
}
