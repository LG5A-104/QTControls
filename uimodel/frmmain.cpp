#include "frmmain.h"
#include "ui_frmmain.h"
#include "api/myhelper.h"

frmMain::frmMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->initStyle();
    this->initForm();
    myHelper::moveFormToCenter(this);
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::initStyle()
{
    this->m_max = false;
    this->locatRect = this->geometry();
    this->setProperty("Form", true);
    this->setProperty("CanMove", true);
    this->setWindowTitle(ui->lab_Title->text());

    //设置窗体标题栏隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //安装事件监听器,让标题栏识别鼠标双击
    ui->lab_Title->installEventFilter(this);

    IconHelper::getInstance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));
    IconHelper::getInstance()->setIcon(ui->btnMenu_Max, QChar(0xf096));
    IconHelper::getInstance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::getInstance()->setIcon(ui->lab_Ico, QChar(0xf015));

    mapStyle["黑色"] = QString(":/qss/black.css");  // 对应的主题样式
    mapStyle["灰黑色"] = QString(":/qss/brown.css");
    mapStyle["灰色"] = QString(":/qss/gray.css");
    mapStyle["浅灰色"] = QString(":/qss/lightgray.css");
    mapStyle["深灰色"] = QString(":/qss/darkgray.css");
    mapStyle["银色"] = QString(":/qss/silvery.css");
    mapStyle["淡蓝色"] = QString(":/qss/blue.css");
    mapStyle["蓝色"] = QString(":/qss/dev.css");

    connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->btnMenu_Min, SIGNAL(clicked()), this, SLOT(showMinimized()));
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        this->on_btnMenu_Max_clicked();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

void frmMain::initForm()
{
    QStringList qssName;
    qssName << "黑色" << "灰黑色" << "灰色" << "浅灰色" << "深灰色" << "银色" << "淡蓝色" << "蓝色";
    ui->cboxStyle->addItems(qssName);

    myHelper::sleep(300);
    ui->cboxStyle->setCurrentIndex(3);
}

void frmMain::on_btnMenu_Max_clicked()
{
    if (m_max) {
        this->setGeometry(locatRect);
        IconHelper::getInstance()->setIcon(ui->btnMenu_Max, QChar(0xf096));
        ui->btnMenu_Max->setToolTip("最大化");
        this->setProperty("CanMove", true);
    } else {
        locatRect = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::getInstance()->setIcon(ui->btnMenu_Max, QChar(0xf079));
        ui->btnMenu_Max->setToolTip("还原");
        this->setProperty("CanMove", false);
    }

    m_max = !m_max;
}

void frmMain::on_pushButton_clicked()
{
    myHelper::showMessageBoxInfo("恭喜你获得我公司送出的1000万元大礼一份!");
}

void frmMain::on_pushButton_2_clicked()
{
    int result = myHelper::showMessageBoxQuesion("确定真的不要我了吗?");
    if (result == 1) {
        myHelper::showMessageBoxInfo("你好狠心啊!");
    } else {
        myHelper::showMessageBoxInfo("亲爱的,我就知道你不会离开我的!");
    }
}

void frmMain::on_pushButton_3_clicked()
{
    myHelper::showMessageBoxError("天空飘来五个字!");
}

void frmMain::on_pushButton_5_clicked()
{
    bool lbok;
    QString value = myHelper::showInputBox("请输入姓名:", lbok);
    if (lbok) {
        myHelper::showMessageBoxInfo("您输入的是:" + value);
    }
}

void frmMain::on_cboxStyle_currentIndexChanged(const QString &text) //@wzguo 2015.09.09
{
    QString qssName = text.trimmed();

    QString qssFile = mapStyle[qssName];

    if (qssFile.trimmed() == "")
        qssFile = ":/qss/black.css";

    myHelper::setStyle(qssFile);
}
