#ifndef OYNA2_H
#define OYNA2_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
namespace Ui {
class oyna2;
}

class oyna2 : public QDialog
{
    Q_OBJECT

public:
    explicit oyna2(QWidget *parent = 0);
    ~oyna2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::oyna2 *ui;
};

#endif // OYNA2_H
