#ifndef ICONHELPER_H
#define ICONHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

class IconHelper : public QObject
{
private:
    explicit IconHelper(QObject *parent = 0);

    QFont iconFont;
    static IconHelper *_instance;

public:
    static IconHelper *getInstance()
    {
        static QMutex mutex;
        if (!_instance)
        {
            QMutexLocker locker(&mutex);
            if (!_instance)
            {
                _instance = new IconHelper;
            }
        }
        return _instance;
    }

    void setIcon(QLabel *lab, QChar chr);
    void setIcon(QPushButton *btn, QChar chr);

};

#endif // ICONHELPER_H
