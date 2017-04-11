#ifndef DEVICESIZETABLE_H
#define DEVICESIZETABLE_H

#include <QTableWidget>

class QProcess;

class DeviceSizeTable : public QTableWidget
{
	Q_OBJECT
public:
    explicit DeviceSizeTable(QWidget *parent = 0);

private:	
	QProcess *process;

private slots:
    void init();
	void readData();
	void checkSize(QString result, QString name);
	void insertSize(QString name, QString use, QString free, QString all, int percent);

public slots:
    void load();
};

#endif // DEVICESIZETABLE_H
