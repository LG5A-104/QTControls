#ifndef SCREENSHOTWINDOW_H
#define SCREENSHOTWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QPixmap>
#include <QPoint>
#include <QtGui>

#include "fullScreenWidget.h"

class screenShotWindow : public QMainWindow
{
  Q_OBJECT
    public:
    screenShotWindow();
    
    public slots:
    void screenshot();//进行截屏的槽函数
    signals:
    void setPixmap(QPixmap pixmap); //设置pixmap信息

    private:
    void createToolBars();
    void createActions();
    QToolBar *mainToolBar;
    QAction *newAct;
    //QLabel *labShotImage;
    QVBoxLayout *mainLayout;
    QPixmap fullPixmap; //全屏图片
    fullScreenWidget *fullWidget;
};

#endif
