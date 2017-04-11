#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::warning(this,tr("new "),tr("new triggled"),QMessageBox::Ok);
}

void MainWindow::on_actionAbout_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}
