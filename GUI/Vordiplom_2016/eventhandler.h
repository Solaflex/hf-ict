#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <mywidget.h>

class eventhandler : public QObject
{
    Q_OBJECT
private:
    MyWidget *parent;
public:
    explicit eventhandler(MyWidget *parent = nullptr);

signals:

public slots:
    void OnCheckButtonClicked();
};

#endif // EVENTHANDLER_H
