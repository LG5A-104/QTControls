#ifndef FRMCONFIG_H
#define FRMCONFIG_H

#include <QWidget>

namespace Ui {
class frmConfig;
}

class frmConfig : public QWidget
{
    Q_OBJECT

public:
    explicit frmConfig(QWidget *parent = 0);
    ~frmConfig();

private:
    Ui::frmConfig *ui;

private slots:
    void initForm();
    void initConfig();
    void saveConfig();
};

#endif // FRMCONFIG_H
