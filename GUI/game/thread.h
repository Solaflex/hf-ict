#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();
    void run();

signals:
    void refresh();
};

#endif // THREAD_H
