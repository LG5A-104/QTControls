#ifndef FRMMAP_H
#define FRMMAP_H

#include <QWidget>

class QPushButton;

namespace Ui {
class frmMap;
}

class frmMap : public QWidget
{
    Q_OBJECT

public:
    explicit frmMap(QWidget *parent = 0);
    ~frmMap();

private:
    Ui::frmMap *ui;

private slots:
    void initForm();
    void buttonClick();
    void buttonCheck(QPushButton *btn);
};

#endif // FRMMAP_H
