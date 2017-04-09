#include "frminputbox.h"
#include "ui_frminputbox.h"
#include "api/myhelper.h"

frmInputBox::frmInputBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmInputBox)
{
    ui->setupUi(this);
    this->initStyle();
    myHelper::moveFormToCenter(this);
}

frmInputBox::~frmInputBox()
{
    delete ui;
}

void frmInputBox::initStyle()
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

void frmInputBox::setMessage(QString title)
{
    ui->labInfo->setText(title);
}

void frmInputBox::on_btnOk_clicked()
{
    strValue = ui->txtValue->text().trimmed();
    done(1);
    this->close();
}
