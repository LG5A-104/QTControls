#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(238, 238, 238));
    setAutoFillBackground(true);
    setPalette(pal);

    QLabel *statusLabel = new QLabel(this);
    statusLabel->setMinimumSize(150, 20); // 设置标签最小大小
    statusLabel->setText(tr("http://www.forward-cn.com/"));
    statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
    QWidget *pWindow = this->window();
    pWindow->close();
}
