#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_3->setText(QString::number(ui->lineEdit->text().toDouble()+ui->lineEdit_2->text().toDouble()));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_3->setText(QString::number(ui->lineEdit->text().toDouble()-ui->lineEdit_2->text().toDouble()));
}

void MainWindow::on_pushButton_3_clicked()
{
     ui->lineEdit_3->setText(QString::number(ui->lineEdit->text().toDouble()*ui->lineEdit_2->text().toDouble()));
}

void MainWindow::on_pushButton_4_clicked()
{
      ui->lineEdit_3->setText(QString::number(ui->lineEdit->text().toDouble()+ui->lineEdit_2->text().toDouble()));}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_3->setText(QString::number(qRadiansToDegrees(ui->lineEdit->text().toDouble())));
}

void MainWindow::on_pushButton_5_clicked()
{
   ui->lineEdit_3->setText(QString::number(qSin(M_PI/180*ui->lineEdit_4->text().toDouble())));
}

void MainWindow::on_pushButton_7_clicked()
{

}

void MainWindow::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{

}
