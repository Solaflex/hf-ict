#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

class eventhandler : public QObject
{
    Q_OBJECT
public:
    explicit eventhandler(QObject *parent = nullptr);

signals:

public slots:
    void OnAddButtonClicked();
};

#endif // EVENTHANDLER_H
