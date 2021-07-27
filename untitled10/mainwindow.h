#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_pressed();

    void on_clear_pressed();

    void on_exit_pressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
