#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QMainWindow>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
