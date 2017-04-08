#include "frmmain.h"
#include <QApplication>
#include <QTextCodec>
#include "frminput.h"
#include "frmnum.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    //QT5版本以上默认就是采用UTF-8编码
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#endif

    qApp->setFont(QFont("Microsoft YaHei", 10));
    //qApp->setFont(QFont("WenQuanYi Micro Hei", 15));

    //在main函数中就加载输入法面板,保证整个应用程序可以使用输入法
    //以下方法打开中文输入法
    frmInput::Instance()->Init("control", "black", 10, 10);
    //以下方法打开数字键盘
//    frmNum::Instance()->Init("lightgray",10);

    frmMain w;
    w.showMaximized();

    return a.exec();
}
