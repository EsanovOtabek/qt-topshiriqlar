#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btn_pressed()
{
    QString fam,ism,shar,adress,vil,lang;
    QString pr="          ",jins="Jinsingiz:"+pr+pr+pr;
    lang="Qaysi tillarni biladi:"+pr;
    //------------------
    fam="Familiyangiz:"+pr+pr+ui->fam->text();
    ism="Ismingiz"+pr+pr+ui->ism->text();
    shar="Otangizng ismi:"+pr+ui->shar->text();
    adress="Oilaviy ahvolingiz:"+pr+pr+ui->adress->text();
    //------------------
    if(ui->jins->isChecked()){
        jins+="Erkak";
    }
    else{
        jins+="Ayol";
    }
    //------------------
    if(ui->lang1->isChecked()){
        lang+="Ingliz tili";
    }
    if(ui->lang2->isChecked()){
        lang+="Rus Tili";
    }
    //------------------
    vil="Viloyatingiz:"+pr+pr+ui->vil->currentText();
    //------------------
    QString year="Tug'ilgan sanangiz:"+pr+ui->year->date().toString("dd/MM/yyyy");
   ui->list->addItem(fam);
   ui->list->addItem(ism);
   ui->list->addItem(shar);
   ui->list->addItem(adress);
   ui->list->addItem(jins);
   ui->list->addItem(year);
   ui->list->addItem(lang);
   ui->list->addItem(vil);
}

void MainWindow::on_formclear_pressed()
{
    ui->fam->clear();
    ui->ism->clear();
    ui->shar->clear();
    ui->adress->clear();
    ui->year->clear();
    ui->fam->clear();
}

void MainWindow::on_listclear_pressed()
{
    ui->list->clear();
    ui->list->addItem("                    Ma'lumotlar\n ");
}
