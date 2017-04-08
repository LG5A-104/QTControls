#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>

namespace Ui
{
    class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

private slots:
    void fileSelected(QString fileName);
    void on_btnDialog_clicked();
    void on_btnInputDialog_clicked();
    void on_btnFileDialog_clicked();

private:
    Ui::frmMain *ui;

};

#endif // FRMMAIN_H
