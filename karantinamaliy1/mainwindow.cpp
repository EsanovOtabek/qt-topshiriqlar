#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QMessageBox>
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
    if(ui->lineEdit_5->text() == "" || ui->lineEdit_6->text() == "" ){
        QMessageBox::information(this," Information", "iltimos maydonlarni to'ldiring");
    }else{
        QString a, b, c;
        a=ui->lineEdit_5->text();
        b=ui->lineEdit_6->text();
        double a1, b1, x0;
        a1=a.toDouble();
        b1=b.toDouble();

        if(a1 != 0){
            ui->label_8->setText("x = " + QString::number(-b1/a1));
        }else{
            ui->label_8->setText("Chiziqli tenglamani yechimi yo'q");
        }
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_3->text() == "" ){
        QMessageBox::information(this," Information", "iltimos maydonlarni to'ldiring");
    }else{
        QString a, b, c;
        a=ui->lineEdit->text();
        b=ui->lineEdit_2->text();
        c=ui->lineEdit_3->text();
        double a1, b1, c1, D, x1, x2, x0;
        a1=a.toDouble();
        b1=b.toDouble();
        c1=c.toDouble();
        D=b1*b1-4*a1*c1;
        if(D>0 && a1!=0){
            x1=(-b1+sqrt(D))/(2*a1);
            x2=(-b1-sqrt(D))/(2*a1);
            ui->label_5->setText("x1 = " + QString::number(x1)+"\n"+"x2 = " + QString::number(x2));
        }
        if(D==0 && a1!=0){
            x0=-b1/(2*a1);
            ui->label_5->setText("x0 = " + QString::number(x0));
        }
        if(D<0){
            ui->label_5->setText("Kvadrat tenlamani yechim yo'q");
        }
        if(a1 == 0){

            ui->label_5->setText("bu kvadrat tenglama bo'la olmaydi");

        }
    }
}
