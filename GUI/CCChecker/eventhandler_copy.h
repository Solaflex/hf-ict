#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include<QObject>
#include<mywidget.h>


class EventHandler : public QObject
{
    Q_OBJECT
private:
    MyWidget *parent;
public:
    EventHandler(MyWidget *mywidget);
public slots:
    void onButtonClicked();
};

#endif // EVENTHANDLER_H
