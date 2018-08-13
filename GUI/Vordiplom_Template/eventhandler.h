#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "mywidget.h"

class eventhandler : public QObject
{
    Q_OBJECT
public:
    explicit eventhandler(MyWidget *parent = nullptr);

signals:

private:
    MyWidget *parent;
public slots:
    void OnButtonAddClicked();
    void OnButtonClearClicked();
    void OnButtonSortClicked();
};

#endif // EVENTHANDLER_H
