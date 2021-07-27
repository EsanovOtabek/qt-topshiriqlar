#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>

namespace Ui {
class sudoku;
}

class sudoku : public QMainWindow
{
    Q_OBJECT

public:
    explicit sudoku(QWidget *parent = 0);
    ~sudoku();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sudoku *ui;
};

#endif // SUDOKU_H
