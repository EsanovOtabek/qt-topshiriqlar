#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QDebug>
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

class qt1 : public QWidget
{
public:
  void onColor()
  {
    QColor color = QColorDialog::getColor(Qt::yellow, this );
    if( color.isValid() )
    {
      qDebug() << "Rangni tanlash : " << color.name();
    }
  }

};


class qt2 : public QWidget
{
public:
  void openFile()
  {
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Ochish",
          QDir::currentPath(),
          "Hamma fayllar (*.*) ;; Document files (*.doc *.rtf);; rasm fayli (*.png)");

    if( !filename.isNull() )
    {
      qDebug() << "faylni tanlash : " << filename.toUtf8();
    }
  }
};

class qt3 : public QWidget
{
public:
  void onFont()
  {
    bool ok;
    QFont font = QFontDialog::getFont(
                    &ok,
                    QFont( "Arial", 18 ),
                    this,
                    tr("tanlash") );
    if( ok )
    {
      qDebug() << "font           : " << font;
      qDebug() << "font weight    : " << font.weight();
      qDebug() << "font family    : " << font.family();
      qDebug() << "font style     : " << font.style();
      qDebug() << "font pointSize : " << font.pointSize();
    }
  }

};

void MainWindow::on_pushButton_pressed()
{
    qt1 color_test;
    color_test.onColor();
}

void MainWindow::on_pushButton_2_pressed()
{
    qt2 test;
     test.openFile();
}

void MainWindow::on_pushButton_3_pressed()
{
    qt3 font_test;
    font_test.onFont();
}

void MainWindow::on_pushButton_4_pressed()
{
    bool ok;
       QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                            tr("Ismingiz:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);

}

void MainWindow::on_pushButton_5_pressed()
{
    int numTasks = 100000;
    QProgressDialog progress("Task in progress...", "Cancel", 0, numTasks, this);
    progress.setWindowModality(Qt::WindowModal);

    for (int i = 0; i < numTasks; i++) {
        progress.setValue(i);

        if (progress.wasCanceled())
            break;
    }
    progress.setValue(numTasks);
}
