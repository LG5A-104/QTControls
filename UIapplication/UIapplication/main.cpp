#include "frmmain.h"
#include "generalAPI/appinit.h"
#include "generalAPI/app.h"
#include <QApplication>
#include "generalAPI/appinit.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    a.setApplicationName(AppName);
    a.setApplicationVersion("1.0");
    a.setFont(QFont(App::FontName, App::FontSize));

    /**Init App configes:set stylesheet ,config.ini logfile and so on*/
    AppInit::Instance()->start();
    frmmain w;
    w.show();

    return a.exec();
}
