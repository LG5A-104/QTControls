#ifndef APP_H
#define APP_H

class QString;

class App
{
public:
    static QString appPath;             //应用程序路径
    static int appFontSize;             //应用程序字体大小
    static QString appFontName;         //应用程序字体名称

    static void readConfig();           //读取配置文件,在main函数最开始加载程序载入
    static QString readConfig(const QString sGroup, const QString skey);
    static QString readConfig(const QString skey);

    static void writeConfig();          //写入配置文件,在更改配置文件程序关闭时调用
    static void writeConfig(const QString sGroup, const QString skey, QString sValue);
    static void writeConfig(const QString skey, QString sValue);
};

#endif // APP_H
