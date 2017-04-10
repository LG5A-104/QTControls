#ifndef FRMMESSAGEBOX_H
#define FRMMESSAGEBOX_H

#include <QDialog>
#include <QMutex>

namespace Ui
{
class frmMessageBox;
}

class frmMessageBox : public QDialog
{
	Q_OBJECT

public:
	explicit frmMessageBox(QWidget *parent = 0);
	~frmMessageBox();

	static frmMessageBox *Instance()
	{
		static QMutex mutex;

		if (!self) {
			QMutexLocker locker(&mutex);

			if (!self) {
				self = new frmMessageBox;
			}
		}

		return self;
	}

	void setMessage(QString msg, int type, int closeSec = 0);

protected:
	void closeEvent(QCloseEvent *);

private slots:
	void on_btnOk_clicked();

private:
	Ui::frmMessageBox *ui;
	static frmMessageBox *self;

	int closeSec;
	int currentSec;

private slots:
	void initStyle();
	void initForm();
	void checkSec();

};

#endif // FRMMESSAGEBOX_H
