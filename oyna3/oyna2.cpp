#include "oyna2.h"
#include "ui_oyna2.h"
#include "QUrl"

oyna2::oyna2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::oyna2)
{
    ui->setupUi(this);

}

oyna2::~oyna2()
{
    delete ui;
}

void oyna2::on_pushButton_clicked()
{

}
