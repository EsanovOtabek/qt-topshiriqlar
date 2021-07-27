#ifndef K_LOGIN_H
#define K_LOGIN_H

#include <QMainWindow>

namespace Ui {
class k_login;
}

class k_login : public QMainWindow
{
    Q_OBJECT

public:
    explicit k_login(QWidget *parent = 0);
    ~k_login();

private:
    Ui::k_login *ui;
};

#endif // K_LOGIN_H
