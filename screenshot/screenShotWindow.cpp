#include "screenShotWindow.h"
#include <QDebug>

screenShotWindow::screenShotWindow()
{
  createActions();
  createToolBars();    
  fullWidget = new fullScreenWidget();
  //labShotImage = new QLabel(tr("display image"),this);;
  //mainLayout = new QVBoxLayout(this);
  connect(newAct,SIGNAL(triggered()),this,SLOT(screenshot()));
  connect(this,SIGNAL(setPixmap(QPixmap)),fullWidget,SLOT(loadBackgroundPixmap(QPixmap)));
  //connect(fullWidget,SIGNAL(finishPixmap(QPixmap)),labShotImage,SLOT(setPixmap(QPixmap)));

  //mainLayout->addWidget(labShotImage);
  //this->setLayout(mainLayout);
  this->resize(500,300);


}

void screenShotWindow::createToolBars()
{
  mainToolBar = new QToolBar("mainToolBar",this);
  mainToolBar->addAction(newAct);
  this->addToolBar(mainToolBar);
}

void screenShotWindow::createActions()
{
  newAct = new QAction(tr("截屏"),this);
}

void screenShotWindow::screenshot()
{
  //hide();
  QPixmap pixmap = fullWidget->getFullScreenPixmap();
  fullWidget->show();

  emit setPixmap(pixmap); //发送信号，使用当前的屏幕的图片作背景图片
}

