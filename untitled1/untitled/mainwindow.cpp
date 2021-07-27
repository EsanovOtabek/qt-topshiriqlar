#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBrush>
#include <QtMath>
#include <QtMultimedia/QSound>
bool btn1=false,btn2=false,btn3=false,btn4=false;
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
    if(btn1)
        btn1=false;
    else{
        btn1=true;
        btn2=false;
        btn3=false;
        btn4=false;
    }
       repaint();
}
void MainWindow::on_pushButton_2_clicked()
{
    if(btn2)
        btn2=false;
    else{
        btn2=true;
        btn1=false;
        btn4=false;
        btn3=false;
    }
       repaint();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(btn3)
        btn3=false;
    else{
        btn3=true;
        btn2=false;
        btn1=false;
        btn4=false;
    }
       repaint();
}
void MainWindow::on_pushButton_4_clicked()
{
    if(btn4)
        btn4=false;
    else{
        btn4=true;
        btn2=false;
        btn1=false;
        btn3=false;
    }
       repaint();
}

void MainWindow::paintEvent(QPaintEvent *event){

    Q_UNUSED(event);
       QPainter painter(this);
       painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
       painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
   if(btn1){
       painter.drawEllipse(200, 150, 250, 250);
   }
   else if(btn2){
       painter.drawRect(QRect(160, 160, 250, 210));

   }
   else if(btn3){
       QPolygonF polygon;
       int n=6;
       for (int i = 0; i < n; ++i) {
       qreal fAngle = 2 * 3.14 * i / n;
       qreal x = 200 + cos(fAngle) * 80;
       qreal y = 200 + sin(fAngle) * 80;
       polygon << QPointF(x, y);
       }
       painter.drawPolygon(polygon);

   }
   else if(btn4){
       QPolygonF polygon;
       polygon<<QPointF(200,200)<<QPointF(200,360)<<QPointF(300,300);
       painter.drawPolygon(polygon);

   }
}






void MainWindow::on_pushButton_5_clicked()
{

    QSound *bells = new QSound("C:/Users/User/Desktop/warning_audio.wav");
    bells->play();
}
