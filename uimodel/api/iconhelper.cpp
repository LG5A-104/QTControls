#include "iconhelper.h"
#include "app.h"

IconHelper *IconHelper::_instance = 0;

IconHelper::IconHelper(QObject *parent)
    :QObject(parent)
{
    int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    iconFont = QFont(fontName);
}

void IconHelper::setIcon(QLabel *lab, QChar chr)
{
    iconFont.setPointSize(App::appFontSize);
    lab->setFont(iconFont);
    lab->setText(chr);
}

void IconHelper::setIcon(QPushButton *btn, QChar chr)
{
    iconFont.setPointSize(App::appFontSize);
    btn->setFont(iconFont);
    btn->setText(chr);
}
