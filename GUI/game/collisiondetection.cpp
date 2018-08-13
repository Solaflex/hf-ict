
#include "collisiondetection.h"
#include "gameobject.h"
#include "shoot.h"
#include "obstacle.h"
#include <QDebug>
#include "gamearea.h"

CollisionDetection::CollisionDetection()
{

}

bool CollisionDetection::check(GameObject *go1, GameObject *go2)
{
    // "game.exe has stopped working"
    // yet it occurs that the code below is running accordingly from time to time, without changing anything........


    bool result = false;


    int positionObject1_X = go1->getX();
    int positionObject1_X_ToEnd = (go1->getX() + go1->width());
    int positionObject1_Y = go1->getY();
    int positionObject1_Y_ToEnd = (go1->getY() + go1->height());

    int positionObject2_X = go2->getX();
    int positionObject2_X_ToEnd = (go2->getX() + go2->width());
    int positionObject2_Y = go2->getY();
    int positionObject2_Y_ToEnd = (go2->getY() + go2->height());

    if((positionObject1_X >= positionObject2_X) && (positionObject1_X <= positionObject2_X_ToEnd) && (positionObject1_Y >= positionObject2_Y) && (positionObject1_Y <= positionObject2_Y_ToEnd)) {
        qDebug() << "collision";
        result = true;
    }

    /*
    int positionObject1 = go1->getX();
    int positionObject1_Y = go1->getY();
    int positionObject2 = go2->getX();
    */

    //qDebug() << "position object 1: " << positionObject1;
    //qDebug() << "position object 2: " << positionObject2;

    return result;      //nothing implemented yet

}
