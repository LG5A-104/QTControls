#include "frmmain.h"
#include <QDebug>
#include <QVBoxLayout>

frmmain::frmmain(QWidget *parent) :
    QWidget(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setWindowFlags(Qt::FramelessWindowHint);
    pTitleBar = new TitleBar(this);

    installEventFilter(pTitleBar);
    setWindowTitle(tr("X-10 Fast Color Meter"));
    setWindowIcon(QIcon(":/images/FosDoc.ico"));

    pMainWindow = new MainWindow(this);

    resize(1000, 800);

//    QPalette pal(palette());
//    pal.setColor(QPalette::Background, QColor(255, 0, 0));
//    setAutoFillBackground(true);
//    setPalette(pal);

    QVBoxLayout *pLayout = new QVBoxLayout();

    pLayout->addWidget(pTitleBar);
    pLayout->addWidget(pMainWindow);

    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(pLayout);
}

frmmain::~frmmain()
{

}



















