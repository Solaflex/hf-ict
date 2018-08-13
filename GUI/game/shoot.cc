#include "shoot.h"
#include "constants.h"
#include <QDebug>
#include <cmath>
#include <QPainter>
#include <QTransform>

Shoot::Shoot(int x, int y, int speed, int angle) :
    GameObject(x, y, Constants::imgFolder + "banana.png", 50)
{
    this->speed = speed;
    this->angle = angle;
    //qDebug() << "actual speed emitted from constructor: " << speed;     //equal to speedSlider value
}

void Shoot::move()
{
    const double g = 9.81;
    double rad = 3.1415926 / 180 * angle;
    int dx = speed/3 * cos(rad) * t;
    int dy = speed/3 * sin(rad) * t - (g/2) * pow(t, 2);
    t = t + 0.1;
    x = x + dx/2;
    y = y - dy/2;

    // y = y + 1;
    //x = x + speed;

    //qDebug() << "actual speed emitted from move(): " << speed;
}
