#include "frmflatui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmFlatUI w;
    w.show();

    return a.exec();
}
