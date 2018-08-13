#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include<QObject>
#include<widget.h>


class EventHandler : public QObject
{
    Q_OBJECT
private:
    Widget *parent;
public:
    EventHandler(Widget *widget);
public slots:
    void onButtonClicked();
    void onResetButtonClicked();
};

#endif // EVENTHANDLER_H
