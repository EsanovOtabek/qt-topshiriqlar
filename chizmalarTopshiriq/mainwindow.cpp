#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QBrush>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QRect m_r2;
       QPoint m_mousePos;

       QObject::connect(this, SIGNAL(needToRepaint()), this, SLOT(repaint()));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}
MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

        QRect r1 = rect().adjusted(10, 10, -10, -10);
        painter.setPen(QColor("#FFFFFF"));
        painter.drawRect(r1);

        QRect r2(QPoint(0, 0), QSize(100, 100));

        m_r2.moveCenter(m_mousePos);

        QPainter painter2;
        QPen pen;
        painter2.setPen(QColor("#000000"));
        pen.setWidth(3);
        painter2.setPen(pen);
        painter2.drawRect(m_r2);
        update();

}
void MainWindow::on_pushButton_clicked()
{
    m_mousePos = event->pos();

     emit needToRepaint();
}
