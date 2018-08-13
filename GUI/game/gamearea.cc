#include <QImage>
#include <QPainter>
#include <vector>
#include "gamearea.h"
#include "gameobject.h"
#include "player.h"
#include "obstacle.h"
#include "shoot.h"
#include "constants.h"
#include "thread.h"
#include <cstdlib>
#include "mainwidget.h"
#include "collisiondetection.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>

GameArea::GameArea(QWidget *parent) : QWidget(parent)
{

    //TODO: work out how resources are included,
    // until then use absolute path with constant
    //QImage img(":/img/background.jpg");
    QImage img(Constants::imgFolder + "background.jpg");
    backgroundImg = new QImage(img.scaledToWidth(1000));

    // the lines below are for test-cases only!
    //GameObject *player = new Player(50, 400);
    //GameObject *obstacle = new Obstacle(500, 350);
    //GameObject *shoot = new Shoot(80, 430, 1, 1);
    //gameObjects.push_back(player);
    //gameObjects.push_back(obstacle);
    //gameObjects.push_back(shoot);
    Thread *t = new Thread();
    connect(t, SIGNAL(refresh()),
            this, SLOT(next()));
    t->start();

    qDebug() << "initialize _shoot and _obstacle with NULL";
    _shoot = NULL;
    _obstacle = NULL;
}

void GameArea::shoot(int speed, int angle)
{

    //create new shoot
    Shoot *_shoot = new Shoot(10,400, speed, angle);
    gameObjects.push_back(_shoot);


}

void GameArea::startGame()
{

    // create player object
    Player *player = new Player(10, 400);
    gameObjects.push_back(player);
    qDebug() << "created player";

    // create obstacle object
    srand(time(NULL));
    int x = (rand() % (width() - 200)) + 200;
    int y = (rand() % (height() - 100)) + 100;
    Obstacle *_obstacle = new Obstacle(x, y);
    gameObjects.push_back(_obstacle);


    gameRunning = 1;    // prevents player and obstacle from being instantiated multiple times when clicking shoot

    //update
    this->update();
}

void GameArea::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    painter->drawImage(0, 0, *backgroundImg);
    for (GameObject *object : gameObjects) {
        object->paint(painter);
    }
    painter->end();
}

void GameArea::next()
{
    for (GameObject *object : gameObjects) {
        object->move();
    }
    if(gameObjects.size() >= 2) {
        _obstacle = gameObjects.begin()[1]; // Get the obstacle in the second position of the vector

        for (GameObject *object : gameObjects) {
            if((object != gameObjects.begin()[0]) && (object != gameObjects.begin()[1])){ //if object is not first or second element of the vector (player and obstacle)
                if (CollisionDetection::check(object, _obstacle))       //COLLISION DETECTION
                {
                    gameObjects.pop_back();
                    qDebug() << "collision";
                    ((MainWidget*)parentWidget())->onGameFinished(); // call the parent widget: https://stackoverflow.com/questions/352758/how-to-access-to-parent-widget-on-qt
                }
            }
        }

    }
    update();
}

void GameArea::clearGameObjects() {
    gameObjects.clear();
}

