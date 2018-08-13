#include "thread.h"
#include <QDebug>

Thread::Thread()
{

}

void Thread::run()
{
    while(true) {
        emit refresh();
        msleep(35);
       // qDebug() << "thread is running!!!!";
    }

}
