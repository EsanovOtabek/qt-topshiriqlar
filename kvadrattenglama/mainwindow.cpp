#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtMath>
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
    float a=ui->lineEdit->text().toFloat();
    float b=ui->lineEdit_2->text().toFloat();
    float c=ui->lineEdit_3->text().toFloat();
    QString str;
    float d=b*b-4*a*c;
    if(d>0){
        float x1,x2;
        x1=-b/2/a+sqrt(d)/2/a;
        x2=-b/2/a-sqrt(d)/2/a;
        str="Tenglama idizlari: x1="+QString::number(x1)+", x2="+QString::number(x2);
    }
    else if(d==0){
        float x;
        x=-b/2/a;
        str="Tenglama ildizi:= "+QString::number(x);
    }
    else{
        str="Tenglama ildizga ega emas";
    }

    QMessageBox::information(this,"Tenglama yechimi:",str,QMessageBox::Ok|QMessageBox::Cancel);
}
