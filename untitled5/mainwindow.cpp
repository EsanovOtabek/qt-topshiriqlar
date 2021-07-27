#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <bits/stdc++.h>
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

QString fio[1000];
int count=0;

void MainWindow::on_addbtn_clicked()
{
    fio[count]=ui->lineEdit->text();
    fio[count].trimmed();
    if(fio[count].size()>0){
        ui->lineEdit->clear();

        ui->listWidget->addItem(fio[count]);
        count++;
    }
}

void MainWindow::on_clearbtn_clicked()
{
    QMessageBox xbb;
    xbb.setText("Shoshmang! Listni tozalashni istaysizmi?");
    xbb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = xbb.exec();
    switch (ret) {
    case QMessageBox::Ok:
        ui->listWidget->clear();
        break;
    default:
        break;
    }
}

void MainWindow::on_lowbtn_clicked()
{
    fio[count]=ui->lineEdit->text();
    fio[count].trimmed();
    if(fio[count].size()>0){
        ui->listWidget_3->addItem(fio[count].toLower());
    }
}

void MainWindow::on_uppbtn_clicked()
{
    fio[count]=ui->lineEdit->text();
    fio[count].trimmed();
    if(fio[count].size()>0){
        ui->listWidget_2->addItem(fio[count].toUpper());
    }
}
