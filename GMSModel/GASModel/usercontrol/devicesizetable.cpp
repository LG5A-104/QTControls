#include "devicesizetable.h"
#include "qprocess.h"
#include "qtablewidget.h"
#include "qheaderview.h"
#include "qfileinfo.h"
#include "qdir.h"
#include "qprogressbar.h"
#include "qtimer.h"

#ifdef Q_OS_WIN
#include "windows.h"
#endif
#define GB (1024 * 1024 * 1024)
#define MB (1024 * 1024)
#define KB (1024)

DeviceSizeTable::DeviceSizeTable(QWidget *parent) : QTableWidget(parent)
{
	init();
    QTimer::singleShot(0, this, SLOT(load()));
}

void DeviceSizeTable::init()
{
	process = new QProcess(this);
	connect(process, SIGNAL(readyRead()), this, SLOT(readData()));

	this->clear();

	//设置列数和列宽
	this->setColumnCount(5);
	this->setColumnWidth(0, 100);
	this->setColumnWidth(1, 100);
	this->setColumnWidth(2, 100);
	this->setColumnWidth(3, 100);
	this->setColumnWidth(4, 150);
    this->setMinimumWidth(600);

	this->setStyleSheet("QTableWidget::item{padding:0px;}");

	QStringList headText;
	headText << "盘符" << "已用空间" << "可用空间" << "总大小" << "已用百分比" ;
	this->setHorizontalHeaderLabels(headText);
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	this->verticalHeader()->setVisible(true);
	this->horizontalHeader()->setStretchLastSection(true);
}

void DeviceSizeTable::load()
{
	//清空原有数据
	int row = this->rowCount();

	for (int i = 0; i < row; i++) {
		this->removeRow(0);
	}

#ifdef Q_OS_WIN
	QFileInfoList list = QDir::drives();

	foreach (QFileInfo dir, list) {
		QString dirName = dir.absolutePath();
		LPCWSTR lpcwstrDriver = (LPCWSTR)dirName.utf16();
		ULARGE_INTEGER liFreeBytesAvailable, liTotalBytes, liTotalFreeBytes;

		if (GetDiskFreeSpaceEx(lpcwstrDriver, &liFreeBytesAvailable, &liTotalBytes, &liTotalFreeBytes)) {
			QString use = QString::number((double)(liTotalBytes.QuadPart - liTotalFreeBytes.QuadPart) / GB, 'f', 1);
			use += "G";
			QString free = QString::number((double) liTotalFreeBytes.QuadPart / GB, 'f', 1);
			free += "G";
			QString all = QString::number((double) liTotalBytes.QuadPart / GB, 'f', 1);
			all += "G";
			int percent = 100 - ((double)liTotalFreeBytes.QuadPart / liTotalBytes.QuadPart) * 100;

			insertSize(dirName, use, free, all, percent);
		}
	}

#else
	process->start("df -h");
#endif
}

void DeviceSizeTable::readData()
{
	while (!process->atEnd()) {
		QString result = QLatin1String(process->readLine());
#ifdef __arm__

		if (result.startsWith("/dev/root")) {
            checkSize(result, "本地存储");
		} else if (result.startsWith("/dev/mmcblk1p1")) {
            checkSize(result, "SD卡");
		} else if (result.startsWith("/dev/sda1")) {
            checkSize(result, "U盘");
		}

#else

		if (result.startsWith("/dev/sda")) {
			checkSize(result, "");
		}

#endif
	}
}

void DeviceSizeTable::checkSize(QString result, QString name)
{
	QString dev, use, free, all;
	int percent = 0;
	QStringList list = result.split(" ");
	int index = 0;

	for (int i = 0; i < list.count(); i++) {
		QString s = list.at(i).trimmed();

		if (s == "") {
			continue;
		}

		index++;

		if (index == 1) {
			dev = s;
		} else if (index == 2) {
			all = s;
		} else if (index == 3) {
			use = s;
		} else if (index == 4) {
			free = s;
		} else if (index == 5) {
			percent = s.left(s.length() - 1).toInt();
			break;
		}
	}

	if (name.length() > 0) {
		dev = name;
	}

	insertSize(dev, use, free, all, percent);
}

void DeviceSizeTable::insertSize(QString name, QString use, QString free, QString all, int percent)
{
	int row = this->rowCount();
	this->insertRow(row);
	this->setRowHeight(row, 25);

	QTableWidgetItem *itemname = new QTableWidgetItem(name);
	QTableWidgetItem *itemuse = new QTableWidgetItem(use);
	itemuse->setTextAlignment(Qt::AlignCenter);
	QTableWidgetItem *itemfree = new QTableWidgetItem(free);
	itemfree->setTextAlignment(Qt::AlignCenter);
	QTableWidgetItem *itemall = new QTableWidgetItem(all);
	itemall->setTextAlignment(Qt::AlignCenter);

	this->setItem(row, 0, itemname);
	this->setItem(row, 1, itemuse);
	this->setItem(row, 2, itemfree);
	this->setItem(row, 3, itemall);

	QProgressBar *bar = new QProgressBar;
	bar->setRange(0, 100);
	bar->setValue(percent);

	QString qss = "QProgressBar{background:#FFFFFF;border-width:0px;border-radius:0px;text-align:center;}";

	if (percent < 50) {
		qss += "QProgressBar{color:#000000;}QProgressBar::chunk{background:#66CD00;}";
	} else if (percent < 90) {
		qss += "QProgressBar{color:#FFFFFF;}QProgressBar::chunk{background:#3C8CDC;}";
	} else {
		qss += "QProgressBar{color:#FFFFFF;}QProgressBar::chunk{background:#D71345;}";
	}

	bar->setStyleSheet(qss);
	this->setCellWidget(row, 4, bar);
}
