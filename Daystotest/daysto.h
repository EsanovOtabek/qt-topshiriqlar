#ifndef DAYSTO_H
#define DAYSTO_H

#include <QMainWindow>

#include <QTimer>
#include <QTime>

namespace Ui {
class daysto;
}

class daysto : public QMainWindow
{
    Q_OBJECT

public:
    explicit daysto(QWidget *parent = 0);
    ~daysto();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::daysto *ui;
    QTimer *tmr;
   private slots:
       void updateTime();
};

#endif // DAYSTO_H
