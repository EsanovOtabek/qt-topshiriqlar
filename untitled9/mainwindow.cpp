#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QtAlgorithms>
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
QString toStr(int number)

{
    if (number == 0)
    return "0";
    QString temp="";
    QString returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
    returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}
void MainWindow::on_pushButton_clicked()
{
    QStringList s;
    QString str="";
    s=ui->a->text().split(',',QString::SkipEmptyParts);
    int n=s.size(),m=ui->m->text().toInt();
    int arr[n],sum=0;
    for(int i=m;i<n;i++){
        arr[i]=s[i].toInt();
        sum+=arr[i];
    }
    str=toStr(sum);
    ui->oss->setText(str);
}
