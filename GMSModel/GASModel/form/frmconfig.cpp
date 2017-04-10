#include "frmconfig.h"
#include "ui_frmconfig.h"
#include "api/myhelper.h"

frmConfig::frmConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmConfig)
{
    ui->setupUi(this);
    this->initForm();
    this->initConfig();
}

frmConfig::~frmConfig()
{
    delete ui;
}

void frmConfig::initForm()
{
    ui->btnConfig->setCheckable(true);
    ui->btnConfig->setChecked(true);

    int btnWidth = 80;
    int btnHeight = 26;

    QList<SwitchButton *> btns1 = ui->gboxBase->findChildren<SwitchButton *>();

    foreach (SwitchButton *btn, btns1) {
        btn->setFixedSize(btnWidth, btnHeight);
    }
}

void frmConfig::initConfig()
{
    QStringList qssName;
    qssName << "黑色风格" << "淡蓝色风格" << "蓝色风格" << "灰黑色风格"
            << "灰色风格" << "浅灰色风格" << "深灰色风格" << "银色风格";
    ui->cboxStyleName->addItems(qssName);

    if (App::StyleName == ":/qss/black.css") {
        ui->cboxStyleName->setCurrentIndex(0);
    } else if (App::StyleName == ":/qss/blue.css") {
        ui->cboxStyleName->setCurrentIndex(1);
    } else if (App::StyleName == ":/qss/dev.css") {
        ui->cboxStyleName->setCurrentIndex(2);
    } else if (App::StyleName == ":/qss/brown.css") {
        ui->cboxStyleName->setCurrentIndex(3);
    } else if (App::StyleName == ":/qss/gray.css") {
        ui->cboxStyleName->setCurrentIndex(4);
    } else if (App::StyleName == ":/qss/lightgray.css") {
        ui->cboxStyleName->setCurrentIndex(5);
    } else if (App::StyleName == ":/qss/darkgray.css") {
        ui->cboxStyleName->setCurrentIndex(6);
    } else if (App::StyleName == ":/qss/silvery.css") {
        ui->cboxStyleName->setCurrentIndex(7);
    }

    connect(ui->cboxStyleName, SIGNAL(currentIndexChanged(int)), this, SLOT(saveConfig()));

    ui->txtTitle->setText(App::Title);
    connect(ui->txtTitle, SIGNAL(textChanged(QString)), this, SLOT(saveConfig()));
}

void frmConfig::saveConfig()
{
    QString style;
    int styleIndex = ui->cboxStyleName->currentIndex();

    if (styleIndex == 0) {
        style = ":/qss/black.css";
    } else if (styleIndex == 1) {
        style = ":/qss/blue.css";
    } else if (styleIndex == 2) {
        style = ":/qss/dev.css";
    } else if (styleIndex == 3) {
        style = ":/qss/brown.css";
    } else if (styleIndex == 4) {
        style = ":/qss/gray.css";
    } else if (styleIndex == 5) {
        style = ":/qss/lightgray.css";
    } else if (styleIndex == 6) {
        style = ":/qss/darkgray.css";
    } else if (styleIndex == 7) {
        style = ":/qss/silvery.css";
    }

    if (style != App::StyleName) {
        App::StyleName = style;
        myHelper::setStyle(App::StyleName);
    }

    App::Title = ui->txtTitle->text();

    App::WriteConfig();
}
