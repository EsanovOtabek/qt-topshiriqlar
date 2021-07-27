#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/baza.db");
    db.setHostName("localhost");
    bool t=db.open();
    if (!t)
      {
         qDebug() << "Error";
      }
      else
      {
         qDebug() << "Database ok!";
      }

    QSqlTableModel *md = new QSqlTableModel(this);

    md->setTable("jadval1");

    md->select();

    ui->tableView->setModel(md);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   int id=ui->lineEdit->text().toInt();
   QString ismi=ui->lineEdit_2->text();
   int yoshi=ui->lineEdit_3->text().toInt();

   QString sqlU="UPDATE jadval1 SET ismi='"+ismi+"', yoshi="+QString::number(yoshi)+" WHERE id="+QString::number(id);
   QSqlQuery qry;
   qry.prepare(sqlU);
   if (qry.exec())
    QMessageBox::information(this,("!"),"OK",QMessageBox::Ok);
   else
    QMessageBox::information(this,("#"),"ERROR",QMessageBox::Ok);

   QSqlTableModel *md = new QSqlTableModel(this);

   md->setTable("jadval1");

   md->select();

   ui->tableView->setModel(md);
}

void MainWindow::on_pushButton_2_clicked()
{
    int rowNum=ui->tableView->currentIndex().row()+1;
    int r=ui->tableView->model()->index(rowNum-1,0).data().toInt();
    QString sqlD="DELETE FROM jadval1 WHERE id="+QString::number(r);
    QMessageBox msg;
    msg.setText("Satrni o'chirmoqchimisiz?");
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msg.exec();
    switch (ret) {
      case QMessageBox::Ok:{
        QSqlQuery res;
        res.prepare(sqlD);
        if(res.exec())
            QMessageBox::information(this,("!"),"O'chirildi",QMessageBox::Ok);
        else
            QMessageBox::information(this,("#"),"Xatolik",QMessageBox::Ok);
          break;}
      case QMessageBox::Cancel:
          break;
    }
    QSqlTableModel *md = new QSqlTableModel(this);

    md->setTable("jadval1");

    md->select();

    ui->tableView->setModel(md);

}

void MainWindow::on_pushButton_3_clicked()
{
    QString ismi=ui->lineEdit_4->text();
    QString yoshi=ui->lineEdit_5->text();
    QString sqlI="INSERT INTO jadval1(ismi, yoshi) VALUES ('"+ismi+"',"+yoshi+")";

    QSqlQuery res;
    res.prepare(sqlI);
    if(res.exec())
        QMessageBox::information(this,("!"),"Qo'shildi",QMessageBox::Ok);
    else
        QMessageBox::information(this,("#"),"Xatolik",QMessageBox::Ok);
    QSqlTableModel *md = new QSqlTableModel(this);

    md->setTable("jadval1");

    md->select();

    ui->tableView->setModel(md);
}
