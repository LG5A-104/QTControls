#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QMenu>
#include "userform/titlebar.h"
#include "userform/mainwindow.h"

class frmmain : public QWidget
{
    Q_OBJECT

public:
    explicit frmmain(QWidget *parent = 0);
    ~frmmain();

private:
    TitleBar *pTitleBar;
    MainWindow *pMainWindow;
};

#endif // FRMMAIN_H
