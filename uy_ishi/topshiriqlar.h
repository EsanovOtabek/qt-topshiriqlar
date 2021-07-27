#ifndef TOPSHIRIQLAR_H
#define TOPSHIRIQLAR_H

#include <QMainWindow>

namespace Ui {
class Topshiriqlar;
}

class Topshiriqlar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Topshiriqlar(QWidget *parent = 0);
    ~Topshiriqlar();

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

private:
    Ui::Topshiriqlar *ui;
};

#endif // TOPSHIRIQLAR_H
