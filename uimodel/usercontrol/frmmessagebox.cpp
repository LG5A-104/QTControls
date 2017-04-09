#include "frmmessagebox.h"
#include "ui_frmmessagebox.h"
#include "api/myhelper.h"

frmMessageBox::frmMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMessageBox)
{
    ui->setupUi(this);
    this->initStyle();
    myHelper::moveFormToCenter(this);
}

frmMessageBox::~frmMessageBox()
{
    delete ui;
}

void frmMessageBox::initStyle()
{
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());
    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图形字体
    IconHelper::getInstance()->setIcon(ui->lab_Ico, QChar(0xf015));
    IconHelper::getInstance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));
    //关联关闭按钮
    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void frmMessageBox::setMessage(QString msg, int type)
{
    if (type == 0) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_info.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("提示");
    } else if (type == 1) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_question.png);");
        ui->lab_Title->setText("询问");
    } else if (type == 2) {
        ui->labIcoMain->setStyleSheet("border-image: url(:/image/msg_error.png);");
        ui->btnCancel->setVisible(false);
        ui->lab_Title->setText("错误");
    }

    ui->labInfo->setText(msg);
    this->setWindowTitle(ui->lab_Title->text());
}

void frmMessageBox::on_btnOk_clicked()
{
    done(1);
    this->close();
}
