#include "app.h"
#include "myhelper.h"

QString App::appPath = "";

#ifdef Q_OS_WIN
int App::appFontSize = 10;
QString App::appFontName = "Microsoft YaHei";
#endif

#ifdef Q_OS_LINUX
#ifdef __arm__
int App::appFontSize = 11;
QString App::appFontName = "WenQuanYi Micro Hei";
#else
int App::appFontSize = 11;
QString App::appFontName = "WenQuanYi";
#endif
#endif

#ifdef Q_OS_MAC
int App::appFontSize = 11;
QString App::appFontName = "Heiti SC";
#endif

void App::readConfig()
{
    readConfig("AppConfig", "skey");
}

QString App::readConfig(const QString sGroup, const QString skey)
{
    QString fileName = App::appPath + "config.txt";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup(sGroup);
    QString sValue = set->value(skey).toString();
    set->endGroup();

    return sValue;
}

QString App::readConfig(const QString skey)
{
    return readConfig("AppConfig", skey);
}

void App::writeConfig()
{
    writeConfig("AppConfig", "skey", "sValue");
}

void App::writeConfig(const QString sGroup, const QString skey, QString sValue)
{
    QString fileName = App::appPath + "config.txt";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup(sGroup);
    set->setValue(skey, sValue);
    set->endGroup();
}

void App::writeConfig(const QString skey, QString sValue)
{
    writeConfig("AppConfig", skey, sValue);
}
