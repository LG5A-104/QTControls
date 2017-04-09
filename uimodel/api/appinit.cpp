#include "appinit.h"
#include "myhelper.h"

AppInit::AppInit(QObject *parent)
    : QObject(parent)
{
    mousePressed = false;
    qApp->installEventFilter(this);
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *wdt = (QWidget *)obj;
    if (!wdt->property("CanMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - wdt->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() && Qt::LeftButton)) {
            wdt->move(event->globalPos() - mousePoint);
            return true;
        }
    }

    return QObject::eventFilter(obj, evt);
}

void AppInit::loadInfo()
{
    myHelper::setTextCode("UTF-8");
    myHelper::setChinese();
    qApp->setFont(QFont(App::appFontName, App::appFontSize));

    App::appPath = QApplication::applicationDirPath();

}
