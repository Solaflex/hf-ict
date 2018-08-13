#ifndef SHOOT_H
#define SHOOT_H

#include "gameobject.h"

class Shoot : public GameObject
{
private:
    int speed;
    int angle;
    double t;

public:
    Shoot(int x, int y, int speed, int angle);
    virtual void move();
    int getSpeed();
};

#endif // SHOOT_H
