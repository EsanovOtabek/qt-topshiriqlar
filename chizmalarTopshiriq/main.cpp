#include "mainwindow.h"
#include <QApplication>
#include <QScopedPointer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QScopedPointer<QWidget> widget(new customWidget());
        widget->resize(240, 120);
        widget->show();
    return a.exec();
}
