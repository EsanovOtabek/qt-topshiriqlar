#include "daysto.h"
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    daysto w;
    w.show();

    QTimer::singleShot(65000, &w, SLOT(close()));

    return a.exec();
}
