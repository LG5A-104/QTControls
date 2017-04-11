#ifndef FRMINPUTBOX_H
#define FRMINPUTBOX_H

#include <QDialog>
#include <QMutex>

namespace Ui
{
class frmInputBox;
}

class frmInputBox : public QDialog
{
	Q_OBJECT

public:
	explicit frmInputBox(QWidget *parent = 0);
	~frmInputBox();

	static frmInputBox *Instance()
	{
		static QMutex mutex;

		if (!self) {
			QMutexLocker locker(&mutex);

			if (!self) {
				self = new frmInputBox;
			}
		}

		return self;
	}

	void setParameter(QString title, int type = 0, int closeSec = 0, QString defaultValue = QString(), bool pwd = false);

	QString getValue()const
	{
		return value;
	}

protected:
	void closeEvent(QCloseEvent *);

private slots:
	void on_btnOk_clicked();

private:
	Ui::frmInputBox *ui;
	static frmInputBox *self;
	QString value;

	int closeSec;
	int currentSec;

private slots:
	void initStyle();
	void initForm();
	void checkSec();

};

#endif // FRMINPUTBOX_H
