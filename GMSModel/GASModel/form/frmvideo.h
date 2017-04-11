#ifndef FRMVIDEO_H
#define FRMVIDEO_H

#include <QWidget>

namespace Ui {
class frmVideo;
}

class frmVideo : public QWidget
{
    Q_OBJECT

public:
    explicit frmVideo(QWidget *parent = 0);
    ~frmVideo();

private:
    Ui::frmVideo *ui;

private slots:
    void initForm();
};

#endif // FRMVIDEO_H
