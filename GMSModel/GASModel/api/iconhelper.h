#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QAbstractButton>
#include <QIcon>
#include <QApplication>

class IconHelper : public QObject
{
public:
	explicit IconHelper(QObject *parent = 0);
	static IconHelper *Instance()
	{
		static QMutex mutex;

		if (!self) {
			QMutexLocker locker(&mutex);

			if (!self) {
				self = new IconHelper;
			}
		}

		return self;
	}

	void setIcon(QLabel *lab, QChar c);
	void setIcon(QAbstractButton *btn, QChar c);

	void setIcon(QLabel *lab, QChar c, int size);
	void setIcon(QAbstractButton *btn, QChar c, int size);

	void setIconMain(QLabel *labMain);
	void setIconMenu(QAbstractButton *btnMenu);
	void setIconMin(QAbstractButton *btnMin);
	void setIconMax(QAbstractButton *btnMax);
	void setIconNormal(QAbstractButton *btnNormal);
	void setIconClose(QAbstractButton *btnClose);

	void setIconMain(QLabel *labMain, int size);
	void setIconMenu(QAbstractButton *btnMenu, int size);
	void setIconMin(QAbstractButton *btnMin, int size);
	void setIconMax(QAbstractButton *btnMax, int size);
	void setIconNormal(QAbstractButton *btnNormal, int size);
	void setIconClose(QAbstractButton *btnClose, int size);

	void setIconSize(QSize iconSize)
	{
		this->iconSize = iconSize;
	}

	void setIconTextColor(QColor iconTextColor)
	{
		this->iconTextColor = iconTextColor;
	}

	void setIconTextSize(int iconTextSize)
	{
		this->iconTextSize = iconTextSize;
	}

	QIcon iconMenu();
	QIcon iconMin();
	QIcon iconMax();
	QIcon iconNormal();
	QIcon iconClose();
	QIcon icon(QChar c);
	QIcon icon(QChar c, int size);

private:
	static IconHelper *self;

	QFont iconFont;
	QSize iconSize;
	QColor iconTextColor;
	int iconTextSize;

};

#endif // ICONHELPER_H
