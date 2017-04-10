#include "frmvideo.h"
#include "ui_frmvideo.h"
#include "api/myhelper.h"

frmVideo::frmVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmVideo)
{
    ui->setupUi(this);
    this->initForm();
}

frmVideo::~frmVideo()
{
    delete ui;
}

void frmVideo::initForm()
{
    QList<QLabel *> labs = this->findChildren<QLabel *>();

    for (int i = 0; i < labs.count(); i++) {
        QLabel *lab = labs.at(i);
        lab->setFrameShape(QFrame::Box);
        lab->setAlignment(Qt::AlignCenter);
        lab->setFocusPolicy(Qt::StrongFocus);
        lab->setText(QString("通道%1").arg(i + 1));
        lab->setObjectName(QString("labVideo%1").arg(i + 1));
    }
}
