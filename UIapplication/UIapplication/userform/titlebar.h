#ifndef TITLEBAR_H
#define TITLEBAR_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include "userform/iconhelper.h"

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

private slots:
    void onClicked();

public:
    void updateMaximize();
    void mouseDoubleClickEvent(QMouseEvent *event);
    // 设置界面标题与图标 安装时间过滤器
    virtual bool eventFilter(QObject *obj, QEvent *event);

private:
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
private:
    bool m_bPressed;
    QPoint m_point;

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // TITLEBAR_H
