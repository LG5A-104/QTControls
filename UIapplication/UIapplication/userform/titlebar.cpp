#include "titlebar.h"
#include <QHBoxLayout>
#include <QApplication>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(30);

    m_bPressed = false;

    QPalette pal(palette());
   // pal.setColor(QPalette::Background, QColor(224, 242, 242));
    pal.setColor(QPalette::Background, QColor(83, 83, 83));
    setAutoFillBackground(true);
    setPalette(pal);

    m_pIconLabel = new QLabel(this);
    m_pTitleLabel = new QLabel(this);

    QFont font;
    font.setPointSize(10);
    font.setFamily(("Tahoma"));
    //font.setBold(true);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);

    //font.setBold(true);
    m_pTitleLabel->setFont(font);
    m_pTitleLabel->setPalette(pe);

    m_pMinimizeButton = new QPushButton(this);
    m_pMaximizeButton = new QPushButton(this);
    m_pCloseButton = new QPushButton(this);

    m_pIconLabel->setFixedSize(20,20);
    m_pIconLabel->setScaledContents(true);

    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //m_pTitleLabel->setAlignment(Qt::AlignHCenter);
    m_pMinimizeButton->setFixedSize(27, 22);
    m_pMaximizeButton->setFixedSize(27, 22);
    m_pCloseButton->setFixedSize(27, 22);

    m_pTitleLabel->setObjectName("whiteLabel");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton->setObjectName("closeButton");

    m_pMinimizeButton->setToolTip("Minimize");
    m_pMaximizeButton->setToolTip("Maximize");
    m_pCloseButton->setToolTip("Close");

    m_pCloseButton->setStyleSheet("QPushButton{background-color:transparent;"
                                  "color: white; border: none;"
                                  "border-style: outset;}"
                                  "QPushButton:hover{background-color:rgb(255,100,100); color: white;}"
                                  "QPushButton:pressed{background-color:rgb(255,100,100);}"
                                  );

    m_pMaximizeButton->setStyleSheet("QPushButton{background-color:transparent;"
                                     "color: white; border: none;"
                                     "border-style: outset;}"
                                     "QPushButton:hover{background-color:rgb(100,100,100); color: white;}"
                                     "QPushButton:pressed{background-color:rgb(100,100,100);}"
                                     );

    m_pMinimizeButton->setStyleSheet("QPushButton{background-color:transparent;"
                                     "color: white; border: none;"
                                     "border-style: outset;}"
                                     "QPushButton:hover{background-color:rgb(100,100,100); color: white;}"
                                     "QPushButton:pressed{background-color:rgb(100,100,100);}"
                                     );

    IconHelper::Instance()->SetIcon(m_pCloseButton, QChar(0xf00d), 12);
    IconHelper::Instance()->SetIcon(m_pMaximizeButton, QChar(0xf079), 12);
    IconHelper::Instance()->SetIcon(m_pMinimizeButton, QChar(0xf068), 12);


    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pIconLabel);
    pLayout->addSpacing(5);
    pLayout->addWidget(m_pTitleLabel);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 0, 5, 0);

    setLayout(pLayout);

    connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar()
{

}
/*
******************************************************************
** 函数名称: TitleBar::onClicked
** 功能概述: 捕获菜单栏三个按键按下事件
** 参数说明:
** 作成日期:20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}
/*
******************************************************************
** 函数名称: TitleBar::updateMaximize
** 功能概述: 更新窗口
** 参数说明: 鼠标事件参数
** 作成日期:20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
       bool bMaximize = pWindow->isMaximized();
       if (bMaximize)
       {
           m_pMaximizeButton->setToolTip(tr("Restore"));
           m_pMaximizeButton->setProperty("maximizeProperty", "restore");
       }
       else
       {
           m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
           m_pMaximizeButton->setToolTip(tr("Maximize"));
       }

       m_pMaximizeButton->setStyle(QApplication::style());
    }
}
/*
******************************************************************
** 函数名称: TitleBar::mouseDoubleClickEvent
** 功能概述: 捕获鼠标双击事件
** 参数说明: 鼠标事件参数
** 作成日期: 20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit m_pMaximizeButton->clicked();
}
/*
******************************************************************
** 函数名称: TitleBar::eventFilter
** 功能概述: 捕获鼠标按下事件
** 参数说明: 鼠标事件参数
** 作成日期:20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
bool TitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
        case QEvent::WindowTitleChange:
        {
            QWidget *pWidget = qobject_cast<QWidget *>(obj);
            if (pWidget)
            {
                m_pTitleLabel->setText(pWidget->windowTitle());
                return true;
            }
        }
        case QEvent::WindowIconChange:
        {
            QWidget *pWidget = qobject_cast<QWidget *>(obj);
            if (pWidget)
            {
                QIcon icon = pWidget->windowIcon();
                m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
                return true;
            }
        }
        case QEvent::WindowStateChange:
        case QEvent::Resize:
            updateMaximize();
            return true;
        default:
            break;
    }
    return QWidget::eventFilter(obj, event);
}
/*
******************************************************************
** 函数名称: TitleBar::mousePressEvent
** 功能概述: 捕获鼠标按下事件
** 参数说明: 鼠标事件参数
** 作成日期: 20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
       m_bPressed = true;
       m_point = event->pos();
    }
}
/*
******************************************************************
** 函数名称: TitleBar::mouseMoveEvent
** 功能概述: 捕获鼠标移动事件
** 参数说明: 鼠标事件参数
** 作成日期: 20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    QWidget *pWindow = this->window();
    //pWindow = parentWidget();
    if (m_bPressed)
        pWindow-> move(event->pos() - m_point + pWindow->pos());
}
/*
******************************************************************
** 函数名称: TitleBar::mouseReleaseEvent
** 功能概述: 捕获鼠标释放事件
** 参数说明: 鼠标事件参数
** 作成日期: 20170415
** 作成者:  zhujf
** 修改日期:
** 修改者:
******************************************************************
*/
void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}
