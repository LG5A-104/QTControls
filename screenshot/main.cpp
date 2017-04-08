#include <QApplication>
#include <QTextCodec>

#include "screenShotWindow.h"

int main(int argc, char *argv[])
{
  QTextCodec *codec = QTextCodec::codecForName("utf-8");
  QTextCodec::setCodecForCStrings(codec);
  QTextCodec::setCodecForLocale(codec);
  QTextCodec::setCodecForTr(codec);
  QApplication app(argc, argv);
  screenShotWindow screenMain;
  screenMain.show();
  return app.exec();
}
