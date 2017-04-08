#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QDialog>
#include <QDebug>
#include "dialog.h"
#include <QLineEdit>


frmMain::frmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);

    //允许键盘输入
//    Dialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
//    dialog.exec();

    //不允许键盘输入
//    Dialog dialog2(this);
//    dialog2.exec();
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::on_btnDialog_clicked()
{
    QDialog *d = new QDialog(this);
    QLineEdit *txt = new QLineEdit(d);
    txt->setVisible(true);
    d->show();
}

void frmMain::on_btnInputDialog_clicked()
{
    QInputDialog *d = new QInputDialog(this);
    d->show();
}

void frmMain::on_btnFileDialog_clicked()
{
    QFileDialog *d = new QFileDialog(this);
    connect(d, SIGNAL(fileSelected(QString)), this, SLOT(fileSelected(QString)));
    d->show();
}

void frmMain::fileSelected(QString fileName)
{    
    QFile file(fileName);
    file.open(QFile::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
}
