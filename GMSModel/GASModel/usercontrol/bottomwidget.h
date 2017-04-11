#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>

class QLabel;

class BottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    QString title;          //标题
    QString version;        //版本
    QString author;         //作者
    QString currentUserName;//当前用户
    QString currentUserType;//当前用户类型
    QString fontName;       //字体
    int fontSize;           //字号
    bool lineFixedWidth;    //分隔符固定宽度

    int day;                //天数
    int hour;               //时钟数
    int minute;             //分钟数
    int seconds;            //秒钟数
    QTimer *timer;          //定时器获取时间
    QLabel *labLive;        //已运行时间标签
    QLabel *labDateTime;    //当前时间标签

private slots:
    void showTime();

public slots:
    void setTitle(QString title);
    void setVersion(QString version);
    void setAuthor(QString author);
    void setCurrentUserName(QString currentUserName);
    void setCurrentUserType(QString currentUserType);
    void setFontName(QString fontName);
    void setFontSize(int fontSize);
    void setLineFixedWidth(bool lineFixedWidth);
    void start(int interval = 1000);
};

#endif // BOTTOMWIDGET_H
