#include "k_login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    k_login w;
    w.show();

    return a.exec();
}
