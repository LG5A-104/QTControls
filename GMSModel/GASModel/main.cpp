#include "form/frmmain.h"
#include <QApplication>
#include "api/appinit.h"
#include "api/myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName(AppName);
    a.setApplicationVersion("1.0");
    a.setWindowIcon(QIcon(":/main.ico"));
    a.setFont(QFont(App::FontName, App::FontSize));

    AppInit::Instance()->start();

    frmMain w;
    w.show();

    return a.exec();
}
