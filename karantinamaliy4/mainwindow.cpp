#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QContextMenuEvent>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menu=new QMenu(this);
    QAction* exa=menu->addAction("TextColor");
    connect(exa,SIGNAL(triggered()),this,SLOT(ishlaf2()));
    QAction* exa2=menu->addAction("BackColor");
    connect(exa2,SIGNAL(triggered()),this,SLOT(ishlaf()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::contextMenuEvent(QContextMenuEvent *e){
    if(menu){
        menu->exec(e->globalPos());
    }
}

void MainWindow::ishlaf(){
    QColorDialog *ncolor=new QColorDialog(this);
    QColor color=ncolor->getColor(Qt::white, this);
    ui->centralWidget->setStyleSheet("background-color:"+color.name());
}

void MainWindow::ishlaf2(){
    QColorDialog *ncolor=new QColorDialog(this);
    QColor color=ncolor->getColor(Qt::white, this);
    ui->label->setStyleSheet("font-size:24px;color:"+color.name());
}
