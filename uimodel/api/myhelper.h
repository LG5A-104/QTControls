#ifndef MYHELPER_H
#define MYHELPER_H

#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif
#include "usercontrol/frmmessagebox.h"
#include "usercontrol/frminputbox.h"
#include "iconhelper.h"
#include "app.h"
#include <QTextCodec>

class myHelper: public QObject
{

public:

    //设置为开机启动
    static void autoRunWithSystem(bool ifAutoRun, QString appName, QString appPath) {
        QSettings *reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (ifAutoRun) {
            reg->setValue(appName, appPath);
        } else {
            reg->setValue(appName, "");
        }
    }

    //设置编码为UTF8
    static void setTextCode(const QString sForName="UTF-8") {
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    }


    //设置指定样式
    static void setStyle(const QString &qssFile) {
        QFile file(qssFile);
        if (file.open(QFile::ReadOnly)) {
            QString qss = QLatin1String(file.readAll());
            qApp->setStyleSheet(qss);
            QString PaletteColor = qss.mid(20, 7);
            qApp->setPalette(QPalette(QColor(PaletteColor)));
            file.close();
        }
    }

    //加载中文字符
    static void setChinese() {
        QTranslator *translator = new QTranslator(qApp);
        translator->load(":/image/qt_zh_CN.qm");
        qApp->installTranslator(translator);
    }

    //判断是否是IP地址
    static bool isIP(const QString sIP) {
        QRegExp RegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return RegExp.exactMatch(sIP);
    }

    //显示输入框
    static QString showInputBox(const QString info, bool &blok) {
        frmInputBox input;

        input.setMessage(info);
        blok = input.exec();

        return input.getValue();
    }

    //显示信息框,仅确定按钮
    static void showMessageBoxInfo(const QString info) {
        frmMessageBox msg;

        msg.setMessage(info, 0);
        msg.exec();
    }

    //显示错误框,仅确定按钮
    static void showMessageBoxError(const QString info) {
        frmMessageBox msg;

        msg.setMessage(info, 2);
        msg.exec();
    }

    //显示询问框,确定和取消按钮
    static int showMessageBoxQuesion(const QString info) {
        frmMessageBox msg;
        msg.setMessage(info, 1);
        return msg.exec();
    }

    //延时
    static void sleep(int sec) {
        QTime dieTime = QTime::currentTime().addMSecs(sec);

        while ( QTime::currentTime() < dieTime ) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    //窗体居中显示
    static void moveFormToCenter(QWidget *frm) {
        int frmX = frm->width();
        int frmY = frm->height();

        QDesktopWidget dwt;

        int deskWidth = dwt.availableGeometry().width();
        int deskHeight = dwt.availableGeometry().height();

        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
        frm->move(movePoint);
    }
};

#endif // MYHELPER_H
