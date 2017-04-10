#include "frmmap.h"
#include "ui_frmmap.h"
#include "api/myhelper.h"
#include "frmvideo.h"

frmMap::frmMap(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::frmMap)
{
	ui->setupUi(this);
	this->initForm();
}

frmMap::~frmMap()
{
	delete ui;
}

void frmMap::initForm()
{
	ui->stackedWidget->addWidget(new frmVideo);

	QString qss = "QTabBar::tab{min-width:47px;min-height:20px;}";

	if (App::UseStyle) {
		qss += "QTabWidget::pane{border:0px;}";
	}

	ui->tabWidget->setStyleSheet(qss);

	QList<QPushButton *> btns = ui->widget_left->findChildren<QPushButton *>();

	foreach (QPushButton *btn, btns) {
		btn->setCheckable(true);
		connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
	}

    ui->btnMapView->click();
}

void frmMap::buttonClick()
{
	QPushButton *btn = (QPushButton *)sender();
	QString name = btn->text();
	buttonCheck(btn);

	if (name == "地图监控") {
		ui->stackedWidget->setCurrentIndex(0);
	} else if (name == "视频监控") {
		ui->stackedWidget->setCurrentIndex(1);
	}
}

void frmMap::buttonCheck(QPushButton *btn)
{
	QList<QPushButton *> btns = ui->widget_left->findChildren<QPushButton *>();

	foreach (QPushButton *b, btns) {
		if (b == btn) {
			b->setChecked(true);
		} else {
			b->setChecked(false);
		}
	}
}
