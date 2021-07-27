#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QDialog>
#include <QColorDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QTextStream>

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
    QString file=QFileDialog::getOpenFileName(this, "Faylni tanlang", "D:/", "*.txt *.html");
    if(!file.isEmpty()){
        QFile ofile(file);
        if(ofile.open(QFile::ReadOnly | QFile::Text)){
            QTextStream in(&ofile);
            QString text=in.readAll();
            ui->textEdit->setPlainText(text);
            ofile.close();
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{

    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
        MainWindow::setStyleSheet("background-color:"+color.name());
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QString saqla=QFileDialog::getSaveFileName(this, "Faylini salash");
        if(!saqla.isEmpty()){
            QString newfile = saqla;
            QFile ofile(newfile);
            if(ofile.open(QFile::WriteOnly | QFile::Text))
            {
                QTextStream out(&ofile);
                out<<ui->textEdit->toPlainText();
                ofile.flush();
                ofile.close();
            }
        }
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 14), this);
    if (ok) {
        ui->textEdit->setFont(font);
    } else {
    }
}



void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Dasturdan chiqishni xohlaysizmi?");
    msgBox.setWindowTitle("Chiqish!!!");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Ok:
        this->close();
        break;
    default:
        break;
    }
}
