#include "iconhelper.h"
#include "myhelper.h"

IconHelper *IconHelper::self = 0;
IconHelper::IconHelper(QObject *):
	QObject(qApp)
{
	int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
	QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
	iconFont = QFont(fontName);

	iconSize = QSize(16, 16);
	iconTextColor = Qt::red;
	iconTextSize = App::FontSize;
}

void IconHelper::setIcon(QLabel *lab, QChar c)
{
	setIcon(lab, c, App::FontSize);
}

void IconHelper::setIcon(QAbstractButton *btn, QChar c)
{
	setIcon(btn, c, App::FontSize);
}

void IconHelper::setIcon(QLabel *lab, QChar c, int size)
{
	iconFont.setPointSize(size);
	lab->setFont(iconFont);
	lab->setText(c);
}

void IconHelper::setIcon(QAbstractButton *btn, QChar c, int size)
{
	iconFont.setPointSize(size);
	btn->setFont(iconFont);
	btn->setText(c);
}

void IconHelper::setIconMain(QLabel *labMain)
{
	setIconMain(labMain, App::FontSize);
}

void IconHelper::setIconMenu(QAbstractButton *btnMenu)
{
	setIconMenu(btnMenu, App::FontSize);
}

void IconHelper::setIconMin(QAbstractButton *btnMin)
{
	setIconMin(btnMin, App::FontSize);
}

void IconHelper::setIconMax(QAbstractButton *btnMax)
{
	setIconMax(btnMax, App::FontSize);
}

void IconHelper::setIconNormal(QAbstractButton *btnNormal)
{
	setIconNormal(btnNormal, App::FontSize);
}

void IconHelper::setIconClose(QAbstractButton *btnClose)
{
	setIconClose(btnClose, App::FontSize);
}

void IconHelper::setIconMain(QLabel *labMain, int size)
{
	iconFont.setPointSize(size);
	labMain->setFont(iconFont);
    labMain->setText(QChar(App::IconMain));
}

void IconHelper::setIconMenu(QAbstractButton *btnMenu, int size)
{
	iconFont.setPointSize(size);
	btnMenu->setFont(iconFont);
	btnMenu->setText(QChar(App::IconMenu));
}

void IconHelper::setIconMin(QAbstractButton *btnMin, int size)
{
	iconFont.setPointSize(size);
	btnMin->setFont(iconFont);
	btnMin->setText(QChar(App::IconMin));
}

void IconHelper::setIconMax(QAbstractButton *btnMax, int size)
{
	iconFont.setPointSize(size);
	btnMax->setFont(iconFont);
	btnMax->setText(QChar(App::IconMax));
}

void IconHelper::setIconNormal(QAbstractButton *btnNormal, int size)
{
	iconFont.setPointSize(size);
	btnNormal->setFont(iconFont);
	btnNormal->setText(QChar(App::IconNormal));
}

void IconHelper::setIconClose(QAbstractButton *btnClose, int size)
{
	iconFont.setPointSize(size);
	btnClose->setFont(iconFont);
	btnClose->setText(QChar(App::IconClose));
}

QIcon IconHelper::iconMenu()
{
	return icon(QChar(App::IconMenu), iconTextSize);
}

QIcon IconHelper::iconMin()
{
	return icon(QChar(App::IconMin), iconTextSize);
}

QIcon IconHelper::iconMax()
{
	return icon(QChar(App::IconMax), iconTextSize);
}

QIcon IconHelper::iconNormal()
{
	return icon(QChar(App::IconNormal), iconTextSize);
}

QIcon IconHelper::iconClose()
{
	return icon(QChar(App::IconClose), iconTextSize);
}

QIcon IconHelper::icon(QChar c)
{
	return icon(c, iconTextSize);
}

QIcon IconHelper::icon(QChar c, int size)
{
	QImage image(iconSize, QImage::Format_ARGB32);
	QPainter painter(&image);
	painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);

	QPen pen = painter.pen();
	pen.setColor(iconTextColor);
	iconFont.setPixelSize(size);
	painter.setPen(pen);
	painter.setFont(iconFont);

	painter.drawText(image.rect(), Qt::AlignCenter, c);
	return QIcon(QPixmap::fromImage(image));
}
