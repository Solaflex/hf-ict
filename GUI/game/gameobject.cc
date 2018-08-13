#include "gameobject.h"
#include "constants.h"


GameObject::GameObject(int x, int y, QString imgPath, int width)
{
    setX(x);
    setY(y);
    img = new QImage(imgPath);
    *img = img->scaledToWidth(width);
}

void GameObject::paint(QPainter *painter)
{
    painter->drawImage(x, y, *img);
}

int GameObject::getY()
{
    return y;
}

void GameObject::setY(int value)
{
    y = value;
}

int GameObject::getX()
{
    return x;
}

void GameObject::setX(int value)
{
    x = value;
}

int GameObject::width()
{
    return img->width();
}

int GameObject::height()
{
    return img->height();
}
