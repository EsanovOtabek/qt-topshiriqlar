#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
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
    QString s="Sizga bir nima haqida xabar bermoqchi bo'lyapti Otabek";
    QMessageBox::information(this,s,"tanlang",QMessageBox::Ok|QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
   QMessageBox::question(this, tr("So'roq"),
                               tr("Telegram kanal ochishni o'ylab ko'ring\n"),
    QMessageBox::Ok|QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::warning(this, tr("Warning"),
                               tr("Ushbu narsani ochish bizning zimmamizda emas.\n"
                                  "Ishonchingiz komilmi?"),
    QMessageBox::Ok | QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::critical(this, tr("Critical"),
                               tr("Bu knopkani bosish orqali siz Otabek tayyorlangan virusni ishga tushurishingiz mumkin.\n"
                                  "Virusdan saqlaning"),
    QMessageBox::Ok | QMessageBox::Cancel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox xabarBox;
    xabarBox.setInformativeText("Siz bir nimani saqlamoqchimisiz");
    xabarBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    xabarBox.setDefaultButton(QMessageBox::Save);
    xabarBox.exec();
}
void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox xabarBox;
    xabarBox.setInformativeText("Siz bir nimani saqlamoqchimisiz");
    xabarBox.setStandardButtons(QMessageBox::Open| QMessageBox::Cancel);
    xabarBox.exec();
}
