#ifndef DATETIMELCD_H
#define DATETIMELCD_H

#include <QLCDNumber>

class QTimer;

class DateTimeLcd : public QLCDNumber
{
    Q_OBJECT
public:
    explicit DateTimeLcd(QWidget *parent = 0);

private:
    bool dotHide;
    QString format;
    int digitCount;
    QTimer *timer;    

public slots:
    void start(int interval = 1000);
    void setDateTime();
    void setDotHide(bool dotHide);
    void setFormat(QString format);
};

#endif // DATETIMELCD_H
