#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db.h"
#include <QMessageBox>
bool LOG_IN;
QString BTN_LOG;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Session user;
    QMessageBox::information(this,"err",user.echo,QMessageBox::Ok);
    LOG_IN = user.isActive();
    BTN_LOG = "LOGIN";
    LOG_IN?BTN_LOG="HOME":BTN_LOG="LOGIN";
    ui->btn_login->setText(BTN_LOG);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_login_clicked()
{
    if(LOG_IN){
        home_page.show();
    }
    else{
        login_page.show();
    }
}
