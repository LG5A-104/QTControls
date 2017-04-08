#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    /*Qt::NonModal       The window is not modal and does not block input to other windows.
  非模态对话框

  Qt::WindowModal        The window is modal to a single window hierarchy and blocks input to its parent window, all grandparent windows, and all siblings of its parent and grandparent windows.
  窗口级模态对话框，即只会阻塞父窗口、父窗口的父窗口及兄弟窗口。（半模态对话框）

  Qt::ApplicationModal       The window is modal to the application and blocks input to all windows.
  应用程序级模态对话框，即会阻塞整个应用程序的所有窗口。（半模态对话框）
  */
//    setWindowModality(Qt::WindowModal);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QWidget * pModalWidget = QApplication::activeModalWidget () ;
    QWidget * pPopupWidget = QApplication::activePopupWidget() ;
    QWidget * pWidget = QApplication::activeWindow() ;
}
