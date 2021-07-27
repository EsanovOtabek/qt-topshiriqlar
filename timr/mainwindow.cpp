#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr = new QTimer(this); tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();
    QDate date(2020,12,12);
    QString st=date.toString("yyyy.MMMM.dddd");
    ui->label_2->setText(st);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;

}
void MainWindow::updateTime()
{
    ui->label->setText(QTime::currentTime().toString()); // Ekrandagi vaqt
}
