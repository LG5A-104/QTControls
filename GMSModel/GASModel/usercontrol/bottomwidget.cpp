#include "bottomwidget.h"
#include "qlabel.h"
#include "qframe.h"
#include "qboxlayout.h"
#include "qtimer.h"
#include "qdatetime.h"
#include "qstyle.h"
#include "qstyleoption.h"
#include "qpainter.h"
BottomWidget::BottomWidget(QWidget *parent) : QWidget(parent)
{
    title = "周界报警监控管理平台";
    version = "V1.0";
    author = "上海某某科技有限公司";
    currentUserName = "admin";
    currentUserType = "管理员";
    fontName = "Microsoft Yahei";
    fontSize = 9;
    lineFixedWidth = false;

    day = 0;
    hour = 0;
    minute = 0;
    seconds = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
}

void BottomWidget::paintEvent(QPaintEvent *)
{
    //加上此代码让继承类样式起作用
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}

void BottomWidget::showTime()
{
    seconds++;

    if (seconds == 60) {
        minute++;
        seconds = 0;
    }

    if (minute == 60) {
        hour++;
        minute = 0;
    }

    if (hour == 24) {
        day++;
        hour = 0;
    }

    QDateTime now = QDateTime::currentDateTime();
    this->labLive->setText(QString("已运行: %1天%2时%3分%4秒").arg(day).arg(hour).arg(minute).arg(seconds));
    this->labDateTime->setText(now.toString("当前时间: yyyy年MM月dd日 HH:mm:ss"));
}

void BottomWidget::setTitle(QString title)
{
    this->title = title;
}

void BottomWidget::setVersion(QString version)
{
    this->version = version;
}

void BottomWidget::setAuthor(QString author)
{
    this->author = author;
}

void BottomWidget::setCurrentUserName(QString currentUserName)
{
    this->currentUserName = currentUserName;
}

void BottomWidget::setCurrentUserType(QString currentUserType)
{
    this->currentUserType = currentUserType;
}

void BottomWidget::setFontName(QString fontName)
{
    this->fontName = fontName;
}

void BottomWidget::setFontSize(int fontSize)
{
    this->fontSize = fontSize;
}

void BottomWidget::setLineFixedWidth(bool lineFixedWidth)
{
    this->lineFixedWidth = lineFixedWidth;
}

void BottomWidget::start(int interval)
{
    QLabel *labWelcom = new QLabel;
    labWelcom->setText(QString("欢迎使用%1 %2").arg(title).arg(version));

    QLabel *labAuthor = new QLabel;
    labAuthor->setText(QString("版权所有: %1").arg(author));

    QLabel *labUser = new QLabel;
    labUser->setText(QString("当前用户: %1【%2】").arg(currentUserName).arg(currentUserType));

    labLive = new QLabel;
    labLive->setText("已运行: 0天0时0分0秒");

    labDateTime = new QLabel;
    labDateTime->setText("当前时间: 2015年1月1日 12:33:33");
    labDateTime->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);

    QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::VLine);
    line2->setFrameShadow(QFrame::Sunken);

    QFrame *line3 = new QFrame;
    line3->setFrameShape(QFrame::VLine);
    line3->setFrameShadow(QFrame::Sunken);

    QFrame *line4 = new QFrame;
    line4->setFrameShape(QFrame::VLine);
    line4->setFrameShadow(QFrame::Sunken);

    if (lineFixedWidth) {
        line1->setFixedWidth(1);
        line2->setFixedWidth(1);
        line3->setFixedWidth(1);
        line4->setFixedWidth(1);
    }

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(6);
    layout->setContentsMargins(6, 6, 6, 6);

    layout->addWidget(labWelcom);
    layout->addWidget(line1);
    layout->addWidget(labAuthor);
    layout->addWidget(line2);
    layout->addWidget(labUser);
    layout->addWidget(line3);
    layout->addWidget(labLive);
    layout->addWidget(line4);
    layout->addWidget(labDateTime);

    QFont font = QFont(fontName, fontSize);
    QList<QLabel *> labs = this->findChildren<QLabel *>();

    foreach (QLabel *lab, labs) {
        lab->setFont(font);
    }

    timer->start(interval);
}
