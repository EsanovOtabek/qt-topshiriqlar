#include "k_login.h"
#include "ui_k_login.h"

k_login::k_login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::k_login)
{
    ui->setupUi(this);
}

k_login::~k_login()
{
    delete ui;
}
