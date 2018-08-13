#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QImage>
#include <QString>
#include <QPainter>

class GameObject
{
private:
    QImage *img;

protected:

    int y;
    int x;
public:
    GameObject(int x, int y, QString imgPath, int width);
    virtual void move() = 0;
    void paint(QPainter *painter);
    int getY();
    void setY(int value);
    int getX();
    void setX(int value);
    int width();
    int height();


public slots:

};

#endif // GAMEOBJECT_H
