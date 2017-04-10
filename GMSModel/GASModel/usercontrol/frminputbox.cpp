#include "frminputbox.h"
#include "ui_frminputbox.h"
#include "api/myhelper.h"

frmInputBox *frmInputBox::self = 0;
frmInputBox::frmInputBox(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::frmInputBox)
{
	ui->setupUi(this);
	this->initStyle();
	this->initForm();
	myHelper::formInCenter(this);
}

frmInputBox::~frmInputBox()
{
	delete ui;
}

void frmInputBox::initStyle()
{
	if (App::UseStyle) {
		this->setProperty("Form", true);
		this->setProperty("CanMove", true);
		this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint |
		                     Qt::WindowMinMaxButtonsHint | Qt::WindowStaysOnTopHint);
		IconHelper::Instance()->setIconMain(ui->lab_Ico, App::FontSize + 2);
		IconHelper::Instance()->setIconClose(ui->btnMenu_Close);
		connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
		this->setFixedSize(280, 150);
	} else {
		this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
		this->resize(size().width(), size().height() - ui->widget_title->size().height());
		ui->widget_title->setVisible(false);
		this->setFixedSize(280, 120);
	}

#ifdef __arm__
	this->setFixedSize(300, 160);
#endif

	this->setWindowTitle(ui->lab_Title->text());
	connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void frmInputBox::initForm()
{
#ifdef __arm__
	int width = 100;
	int iconWidth = 22;
	int iconHeight = 22;
#else
	int width = 80;
	int iconWidth = 18;
	int iconHeight = 18;
#endif

	QList<QPushButton *> btns1 = ui->frame->findChildren<QPushButton *>();

	foreach (QPushButton *btn, btns1) {
		btn->setMinimumWidth(width);
		btn->setIconSize(QSize(iconWidth, iconHeight));
	}

	closeSec = 0;
	currentSec = 0;

	QTimer *timer = new QTimer(this);
	timer->setInterval(1000);
	connect(timer, SIGNAL(timeout()), this, SLOT(checkSec()));
	timer->start();
}

void frmInputBox::checkSec()
{
	if (closeSec == 0) {
		return;
	}

	if (currentSec < closeSec) {
		currentSec++;
	} else {
		this->close();
	}

	if (App::UseStyle) {
		QString str = QString("关闭倒计时 %1 s").arg(closeSec - currentSec + 1);
		ui->labTime->setText(str);
	} else {
		QString str = QString("%1  关闭倒计时 %2 s").arg(ui->lab_Title->text()).arg(closeSec - currentSec + 1);
		this->setWindowTitle(str);
	}
}

void frmInputBox::setParameter(QString title, int type, int closeSec, QString defaultValue, bool pwd)
{
	this->closeSec = closeSec;
	this->currentSec = 0;
	ui->labTime->clear();
	checkSec();

	ui->labInfo->setText(title);

	if (type == 0) {
		ui->cboxValue->setVisible(false);
		ui->txtValue->setPlaceholderText(defaultValue);

		if (pwd) {
			ui->txtValue->setEchoMode(QLineEdit::Password);
		}
	} else if (type == 1) {
		ui->txtValue->setVisible(false);
		ui->cboxValue->addItems(defaultValue.split("|"));
	}
}

void frmInputBox::closeEvent(QCloseEvent *)
{
	closeSec = 0;
	currentSec = 0;
}

void frmInputBox::on_btnOk_clicked()
{
	if (ui->txtValue->isVisible()) {
		value = ui->txtValue->text();
	} else if (ui->cboxValue->isVisible()) {
		value = ui->cboxValue->currentText();
	}

	done(1);
	this->close();
}
