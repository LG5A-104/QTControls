#ifndef SAVELOG_H
#define SAVELOG_H

#include <QObject>
#include <QMutex>

class SaveLog : public QObject
{
	Q_OBJECT
public:
    explicit SaveLog(QObject *parent = 0);
    static SaveLog *Instance()
	{
		static QMutex mutex;

		if (!self) {
			QMutexLocker locker(&mutex);

			if (!self) {
                self = new SaveLog;
			}
		}

		return self;
	}

	void start();
	void stop();

private:
    static SaveLog *self;
};

#endif // SAVELOG_H
