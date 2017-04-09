#include "frmmain.h"
#include <QApplication>
#include "api/appinit.h"

int main(int argc, char *argv[])
{
    QApplication appc(argc, argv);

    AppInit *initApp = new AppInit;
    initApp->loadInfo();

    frmMain wmin;
    wmin.show();

    return appc.exec();
}
