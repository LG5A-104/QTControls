#include "frmmain.h"
#include "ui_frmmain.h"
#include "api/myhelper.h"
#include "frmmap.h"
#include "frmconfig.h"

frmMain::frmMain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->initStyle();
    this->initForm();
    myHelper::formInCenter(this);

    if (App::UseStyle) {
        on_btnMenu_Max_clicked();
    } else {
        this->showMaximized();
    }
}

frmMain::~frmMain()
{
    delete ui;
}

bool frmMain::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->widget_title) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            this->on_btnMenu_Max_clicked();
            return true;
        }
    }

    return QWidget::eventFilter(obj, event);
}

void frmMain::initStyle()
{
    IconHelper::Instance()->setIconClose(ui->btnMenu_Close);
    IconHelper::Instance()->setIconNormal(ui->btnMenu_Max);
    IconHelper::Instance()->setIconMin(ui->btnMenu_Min);

#ifdef __arm__
    IconHelper::Instance()->setIconMain(ui->lab_Ico, 60);
    ui->lab_Title->setFont(QFont(App::FontName, 35));
    //ui->lab_Ico->setFixedWidth(100);
    ui->labCPUMemory->setFixedWidth(500);
    ui->lcdNumber->setFixedWidth(500);
#else
    IconHelper::Instance()->setIconMain(ui->lab_Ico, 40);
    ui->lab_Title->setFont(QFont(App::FontName, 18));
    //ui->lab_Ico->setFixedWidth(80);
    ui->labCPUMemory->setFixedWidth(380);
    ui->lcdNumber->setFixedWidth(380);
#endif

    if (App::UseStyle) {
        this->max = false;
        this->location = this->geometry();
        this->setProperty("Form", true);
        this->setProperty("CanMove", true);
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
        connect(ui->btnMenu_Close, SIGNAL(clicked()), this, SLOT(close()));
    } else {
        this->setWindowFlags(Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
        this->resize(size().width(), size().height() - ui->widget_title->size().height());
    }

    ui->widget_title->installEventFilter(this);
    ui->labCPUMemory->setVisible(false);
    ui->lcdNumber->setVisible(false);
    //ui->widget_menu->setVisible(false);

    ui->lab_Title->setText(App::Title);
    this->setWindowTitle(ui->lab_Title->text());
}

void frmMain::initForm()
{
    ui->stackedWidget->addWidget(new frmMap);
    ui->stackedWidget->addWidget(new frmConfig);
    ui->stackedWidget->addWidget(new QWidget);
    ui->stackedWidget->addWidget(new QWidget);

#ifdef __arm__
    int width = 25;
    int interval = 5000;
#else
    int width = 20;
    int interval = 1000;
#endif

    if (App::UseStyle) {
        QStringList qss;
        qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{width:%1px;}").arg(width));
        qss.append("QListWidget::item,QTreeView::item{padding:3px;margin:0px;}");
        this->setStyleSheet(qss.join(""));
    }

    QString qss = QString("QLabel,QLCDNumber{background-color:rgb(0,0,0);color:rgb(%1);}").arg("255,107,107");
    ui->lcdNumber->setStyleSheet(qss);
    ui->labCPUMemory->setStyleSheet(qss);

    ui->lcdNumber->start();
    ui->labCPUMemory->start(interval);

    ui->widget_bottom->setTitle(App::Title);
    ui->widget_bottom->setLineFixedWidth(App::UseStyle);
    ui->widget_bottom->start();

    QList<QToolButton *> btns = ui->widget_top->findChildren<QToolButton *>();

#ifdef __arm__
    QSize icoSize(38, 38);
    int icoWidth = 105;
#else
    QSize icoSize(32, 32);
    int icoWidth = 85;
#endif

    foreach (QToolButton *btn, btns) {
        btn->setCheckable(true);
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }

    ui->btnMain->click();
}

void frmMain::buttonClick()
{
    QToolButton *btn = (QToolButton *)sender();
    QString name = btn->text();
    buttonCheck(btn);

    if (name == "主界面") {
        ui->stackedWidget->setCurrentIndex(0);
    } else if (name == "系统设置") {
        ui->stackedWidget->setCurrentIndex(1);
    } else if (name == "警情查询") {
        ui->stackedWidget->setCurrentIndex(2);
    } else if (name == "调试帮助") {
        ui->stackedWidget->setCurrentIndex(3);
    } else if (name == "用户退出") {
        close();
    }
}

void frmMain::buttonCheck(QToolButton *btn)
{
    QList<QToolButton *> btns = ui->widget_top->findChildren<QToolButton *>();

    foreach (QToolButton *b, btns) {
        if (b == btn) {
            b->setChecked(true);
        } else {
            b->setChecked(false);
        }
    }
}

void frmMain::on_btnMenu_Min_clicked()
{
    if (App::UseTray) {
        QString msg = "程序已经最小化到后台运行!";
        trayIcon->showMessage(App::Title, msg, QSystemTrayIcon::Information, 1);
        this->hide();
    } else {
        this->showMinimized();
    }
}

void frmMain::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        IconHelper::Instance()->setIconNormal(ui->btnMenu_Max);
        ui->btnMenu_Max->setToolTip("最大化");
        this->setProperty("CanMove", true);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        IconHelper::Instance()->setIconMax(ui->btnMenu_Max);
        ui->btnMenu_Max->setToolTip("还原");
        this->setProperty("CanMove", false);
    }

    max = !max;
}

void frmMain::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick: {
        showNormal();
        break;
    }

    default:
        break;
    }
}
