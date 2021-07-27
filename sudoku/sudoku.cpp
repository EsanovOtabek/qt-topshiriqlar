#include "sudoku.h"
#include "ui_sudoku.h"
#include <QTableWidget>
#include <QMessageBox>
using namespace std;

int sud[9][9],kk=0;
sudoku::sudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sudoku)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(9);
    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            QTableWidgetItem *kt=new QTableWidgetItem;
            kt->setText(QString::number(0));
            ui->tableWidget->setItem(j,i,kt);
        }
    }
}

bool colx(int col, int num){
   for (int row = 0; row < 9; row++)
      if (sud[row][col] == num)
         return true;
   return false;
}
bool rowx(int row, int num){
   for (int col = 0; col < 9; col++)
      if (sud[row][col] == num)
         return true;
   return false;
}
bool box9(int br, int bc, int num){

   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (sud[row+br][col+bc] == num)
            return true;
   return false;
}
bool finds(int &row, int &col){
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (sud[row][col] == 0)
            return true;
   return false;
}
bool joy(int row, int col, int num){
   return !rowx(row, num) && !colx(col, num) && !box9(row - row%3 ,
col - col%3, num);
}
bool solve(){
   int row, col;
   if (!finds(row, col))
      return true;
   for (int num = 1; num <= 9; num++){
      if (joy(row, col, num)){
         sud[row][col] = num;
         if (solve())
            return true;
         sud[row][col] = 0;
      }
   }
   return false;
}
sudoku::~sudoku()
{
    delete ui;
}

void sudoku::on_pushButton_clicked()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            sud[i][j]=ui->tableWidget->item(i,j)->text().toInt();
        }
    }
    if(solve()){
        for (int row = 0; row < 9; row++){
           for (int col = 0; col < 9; col++){
              ui->tableWidget->item(row,col)->setText(QString::number(sud[row][col]));
           }
        }
    }
    else{
         QMessageBox::warning(this, tr("Warning"),
                              tr("Siz kiritgan sonlar Sudoku bo'la olmaydi.\n"),
                              QMessageBox::Ok | QMessageBox::Cancel);
    }
}

void sudoku::on_pushButton_2_clicked()
{
    for (int row = 0; row < 9; row++){
       for (int col = 0; col < 9; col++){
          ui->tableWidget->item(row,col)->setText(QString::number(0));
       }
    }
}
