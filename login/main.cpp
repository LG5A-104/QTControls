#include "loginwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget w;
    w.show();

    return a.exec();
}
