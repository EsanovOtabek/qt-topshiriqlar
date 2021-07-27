#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
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
int oRand(){
     qint32 a=333,b=3;
     return qrand()%(a+1)-b;
}
int satr,ustun;
void MainWindow::on_pushButton_clicked()
{
    satr=ui->lineEdit->text().toInt();
    ustun=ui->lineEdit_2->text().toInt();

    ui->tableWidget->setColumnCount(satr);
    ui->tableWidget->setRowCount(ustun+1);

   QString s="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstauvwxyz";
   QStringList sList;
   for(int i=0;i<satr;i++)
       sList.insert(i,""+s[i]);
   ui->tableWidget->setHorizontalHeaderLabels(sList);
    QStringList sList2;
   for(int i=0;i<ustun;i++)
       sList2.insert(i,""+s[i]);
   ui->tableWidget->setVerticalHeaderLabels(sList2);

    for(int i=0; i<satr; i++){
        for(int j=0;j<ustun;j++){
            QTableWidgetItem *kt=new QTableWidgetItem;
            kt->setText(QString::number(oRand()));
            ui->tableWidget->setItem(j,i,kt);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    int max=0,colA,rowA;
    int col=ui->tableWidget->columnCount();
    int row=ui->tableWidget->rowCount()-1;
    for(int i=0; i<col; i++){
        for(int j=0;j<row;j++){
            int f=ui->tableWidget->item(j,i)->text().toInt();
            if(max<f){
                max=f;
                colA=i;
                rowA=j;
            }
        }
    }
    ui->tableWidget->item(rowA,colA)->setBackgroundColor((Qt::blue));
}

void MainWindow::on_pushButton_4_clicked()
{

    int col=ui->tableWidget->columnCount();
    int row=ui->tableWidget->rowCount()-1;
    int min=1000,colA=-1,rowA=-1;
    for(int i=0; i<col; i++){
        for(int j=0;j<row;j++){
            int f=ui->tableWidget->item(j,i)->text().toInt();
            if(min>f){
                min=f;
                colA=i;
                rowA=j;
            }
        }
    }
    ui->tableWidget->item(rowA,colA)->setBackgroundColor(Qt::yellow);

}

void MainWindow::on_pushButton_5_clicked()
{

    int col=ui->tableWidget->columnCount();
    int row=ui->tableWidget->rowCount()-1;
    for(int i=0; i<col; i++){
        qint32 s=0;
        for(int j=0;j<row-1;j++){
            int f=ui->tableWidget->item(j,i)->text().toInt();
            s=s+f;

        }

        QTableWidgetItem *kt=new QTableWidgetItem;
        kt->setText(QString::number(s));
        ui->tableWidget->setItem(row,i,kt);
    }
}
