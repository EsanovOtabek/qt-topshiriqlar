#include "topshiriqlar.h"
#include "ui_topshiriqlar.h"
#include <QFileDialog>
#include <QPixmap>
Topshiriqlar::Topshiriqlar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Topshiriqlar)
{
    ui->setupUi(this);
    ui->lineEdit->setInputMask("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    ui->lineEdit_2->setValidator( new QIntValidator(0, 100, this) );
    ui->satr->setValidator( new QIntValidator(0, 100, this) );
    ui->ustun->setValidator( new QIntValidator(0, 100, this) );
}

Topshiriqlar::~Topshiriqlar()
{
    delete ui;
}
void Topshiriqlar::on_pushButton_pressed()
{
 QString str=ui->lineEdit->text().toUpper();
 ui->label_2->setText(str);
}
void timer(){
    int a=0;
    for(int i=0;i<1e+7;i++){
        a++;
    }
}

void Topshiriqlar::on_pushButton_2_pressed()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Rasmni Tanlang"),"/home",tr("Images(*.png *.jpg)"));
    QPixmap pixmap(filename);
    ui->label_4->setPixmap(pixmap);
}

void Topshiriqlar::on_pushButton_3_pressed()
{
    int val=ui->lineEdit_2->text().toInt();
    ui->progressBar->setValue(0);
    for(int i=0;i<=val;i++){
        timer();
        ui->progressBar->setValue(i);
    }

}

void Topshiriqlar::on_pushButton_4_pressed()
{
    int satr=ui->satr->text().toInt();
    int ustun=ui->ustun->text().toInt();
    ui->tableWidget->setColumnCount(ustun);
    ui->tableWidget->setRowCount(satr);
    for(int row = 0; row<satr; row++)
          for(int col = 0; col<ustun; col++)
              ui->tableWidget->setItem(row, col, new QTableWidgetItem());

}
