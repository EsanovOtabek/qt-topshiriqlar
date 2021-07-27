#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <bits/stdc++.h>
using namespace std;
string son(char son1)

{

     switch(son1)

    {

        case '0':return "";         break;

        case '1':return "bir ";     break;

        case '2':return "ikki ";    break;

        case '3':return "uch ";     break;

        case '4':return "to'rt ";   break;

        case '5':return "besh ";    break;

        case '6':return "olti ";    break;

        case '7':return "yetti ";   break;

        case '8':return "sakkiz ";  break;

        case '9':return "to'qqiz "; break;

    }

}

string onlar(char son1)

{

  switch(son1){

    case '0':return "";         break;

    case '1':return "o'n ";     break;

    case '2':return "yigirma "; break;

    case '3':return "o'ttiz ";  break;

    case '4':return "qirq ";    break;

    case '5':return "ellik ";   break;

    case '6':return "oltmish "; break;

    case '7':return "yetmish "; break;

    case '8':return "sakson ";  break;

    case '9':return "to'qson "; break;

    }

}

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

void MainWindow::on_btn_pressed()
{
    string s=ui->son->text().toStdString();

    string soz="",soz_="";

    int n,L;

    L=s.length();

    if(L<=12){

        for(int i=1;i<=12-L;i++)

        {

            s="0"+s;

        }

    }

    L=s.length();


    for(int i=0;i<12;i+=3)

    {

        soz+=son(s[i]);

        if(s[i]!='0'){soz+="yuz ";}

        soz+=onlar(s[i+1]);

        soz+=son(s[i+2]);

        if((s[i]!='0' || s[i+1]!='0' || s[i+2]!='0') && i==0 ){soz+="milliard ";}

        if((s[i]!='0' || s[i+1]!='0' || s[i+2]!='0') && i==3 ){soz+="million ";}

        if((s[i]!='0' || s[i+1]!='0' || s[i+2]!='0') && i==6 ){soz+="ming ";}

    }

    L=soz.length();

    for(int i=0;i<L-1;i++)

    {

       soz_+=soz[i];

    }

    L=soz_.length();
    QString txt=QString::fromStdString(soz_);
    QMessageBox xbb;
    xbb.setText(txt);
    xbb.exec();
}

void MainWindow::on_clear_pressed()
{
    ui->son->clear();
}

void MainWindow::on_exit_pressed()
{
    MainWindow::close();
}
