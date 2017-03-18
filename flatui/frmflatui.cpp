#include "frmflatui.h"
#include "ui_frmflatui.h"
#include "flatui.h"
#include "qdebug.h"

frmFlatUI::frmFlatUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmFlatUI)
{
    ui->setupUi(this);
    this->initForm();
}

frmFlatUI::~frmFlatUI()
{
    delete ui;
}

void frmFlatUI::initForm()
{
    ui->bar1->setRange(0, 100);
    ui->bar2->setRange(0, 100);
    ui->slider1->setRange(0, 100);
    ui->slider2->setRange(0, 100);

    connect(ui->slider1, SIGNAL(valueChanged(int)), ui->bar1, SLOT(setValue(int)));
    connect(ui->slider2, SIGNAL(valueChanged(int)), ui->bar2, SLOT(setValue(int)));
    ui->slider1->setValue(30);
    ui->slider2->setValue(30);

    this->setStyleSheet("*{outline:0px;}QWidget#frmFlatUI{background:#FFFFFF;}");

    FlatUI::Instance()->setPushButtonQss(ui->btn1, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");
    FlatUI::Instance()->setPushButtonQss(ui->btn2, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->btn3, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->btn4, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    FlatUI::Instance()->setLineEditQss(ui->txt1, "#DCE4EC", "#34495E");
    FlatUI::Instance()->setLineEditQss(ui->txt2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->txt3, "#DCE4EC", "#3498DB");
    FlatUI::Instance()->setLineEditQss(ui->txt4, "#DCE4EC", "#E74C3C");

    FlatUI::Instance()->setProgressBarQss(ui->bar1, "#E8EDF2", "#E74C3C");
    FlatUI::Instance()->setProgressBarQss(ui->bar2, "#E8EDF2", "#1ABC9C");

    FlatUI::Instance()->setSliderQss(ui->slider1, "#E8EDF2", "#1ABC9C", "#1ABC9C");
    FlatUI::Instance()->setSliderQss(ui->slider2, "#E8EDF2", "#E74C3C", "#E74C3C");
    FlatUI::Instance()->setSliderQss(ui->slider3, "#E8EDF2", "#34495E", "#34495E");

    FlatUI::Instance()->setRadioButtonQss(ui->rbtn1, "#D7DBDE", "#34495E");
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn2, "#D7DBDE", "#1ABC9C");
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn3, "#D7DBDE", "#3498DB");
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn4, "#D7DBDE", "#E74C3C");

    FlatUI::Instance()->setCheckBoxQss(ui->ck1, "#D7DBDE", "#34495E");
    FlatUI::Instance()->setCheckBoxQss(ui->ck2, "#D7DBDE", "#1ABC9C");
    FlatUI::Instance()->setCheckBoxQss(ui->ck3, "#D7DBDE", "#3498DB");
    FlatUI::Instance()->setCheckBoxQss(ui->ck4, "#D7DBDE", "#E74C3C");

    FlatUI::Instance()->setScrollBarQss(ui->horizontalScrollBar, "#606060", "#34495E", "#1ABC9C", "#E74C3C");
    FlatUI::Instance()->setScrollBarQss(ui->verticalScrollBar, "#606060", "#34495E", "#1ABC9C", "#E74C3C");
}
