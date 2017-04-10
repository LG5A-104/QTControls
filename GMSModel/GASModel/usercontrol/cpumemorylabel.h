#ifndef CPUMEMORYLABEL_H
#define CPUMEMORYLABEL_H

/**
 * CPU内存显示控件 作者:feiyangqingyun(QQ:517216493) 2016-11-18
 * 1:实时显示当前CPU及内存使用情况,包括共多少内存已使用多少内存
 * 2:全平台通用,包括windows,linux,ARM
 */

#include <QLabel>

class QProcess;

class CpuMemoryLabel : public QLabel
{
    Q_OBJECT
public:
    CpuMemoryLabel(QWidget *parent = 0);

private:
    int totalNew, idleNew, totalOld, idleOld;
    int cpuPercent;

    int memoryPercent;
    int memoryAll;
    int memoryUse;
    int memoryFree;

    QTimer *timerCPU;       //定时器获取CPU信息
    QTimer *timerMemory;    //定时器获取内存信息
    QProcess *process;      //linux执行命令

private slots:
    void getCPU();          //获取cpu
    void getMemory();       //获取内存
    void readData();        //读取数据
    void setData();         //设置数据

public slots:
    void start(int interval);
    void stop();

signals:
    void textChanged(QString text);
};

#endif // CPUMEMORYLABEL_H
