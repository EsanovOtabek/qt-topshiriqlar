#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;
QString str;
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

void MainWindow::on_choose_pressed()
{
    str=ui->comboBox->currentText();
    if(str=="Massa"){
        ui->a1->setText("kg");
        ui->b1->setText("milligram");
        ui->c1->setText("gramm");
        ui->d1->setText("tonna");
    }
    else if(str=="Uzunlik"){
        ui->a1->setText("m");
        ui->b1->setText("millimetr");
        ui->c1->setText("santimetr");
        ui->d1->setText("kilometr");
    }
    else{
        ui->a1->setText("soat");
        ui->b1->setText("soniya");
        ui->c1->setText("minut");
        ui->d1->setText("kun");
    }

}

void MainWindow::on_btn_pressed()
{
    float a=ui->a->text().toFloat();
    str=ui->comboBox->currentText();
    if(str=="Massa"){
        ui->b->setNum(a/1000000);
        ui->c->setNum(a/1000);
        ui->d1->setNum(a*1000);
    }
    else if(str=="Uzunlik"){
        ui->b->setNum(a/1000);
        ui->c->setNum(a/100);
        ui->d1->setNum(a*1000);
    }
    else{
        ui->b->setNum(a*3600);
        ui->c->setNum(a*60);
        ui->d1->setNum(a/24);
    }
}
