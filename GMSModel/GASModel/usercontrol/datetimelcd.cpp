#include "datetimelcd.h"
#include "qtimer.h"
#include "qdatetime.h"

DateTimeLcd::DateTimeLcd(QWidget *parent) : QLCDNumber(parent)
{
    setDotHide(false);
	setFormat("yyyy-MM-dd HH:mm:ss");
	this->setSegmentStyle(QLCDNumber::Flat);

	timer = new QTimer(this);
	timer->setInterval(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(setDateTime()));
}

void DateTimeLcd::start(int interval)
{
	setDateTime();
	timer->start(interval);
}

void DateTimeLcd::setDateTime()
{
	static bool isHide = false;
	QDateTime now = QDateTime::currentDateTime();
	QString str = now.toString(format);

	if (dotHide) {
		if (!isHide) {
			str = str.replace(":", " ");
        }

		isHide = !isHide;
	}

	this->display(str);
}

void DateTimeLcd::setDotHide(bool dotHide)
{
	this->dotHide = dotHide;
}

void DateTimeLcd::setFormat(QString format)
{
	this->format = format;

	if (format == "yyyy-MM-dd HH:mm:ss") {
		digitCount = 19;
	} else if (format == "yyyy-MM-dd") {
		digitCount = 10;
	} else if (format == "HH:mm:ss") {
		digitCount = 8;
	}

	this->setDigitCount(digitCount);
}
