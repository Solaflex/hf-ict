
#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QWidget>
#include <vector>
#include "gameobject.h"
#include "shoot.h"
#include "mainwidget.h"
#include <QMessageBox>

class QImage;
class QPaintEvent;


class GameArea : public QWidget
{
    Q_OBJECT
    
private:
    QImage *backgroundImg;
    std::vector<GameObject *> gameObjects;
    GameObject *_shoot;
    GameObject *_obstacle;
    QMessageBox *score;

public:
    explicit GameArea(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void startGame();
    void shoot(int speed, int angle);
    void gameFinished();
    bool gameRunning;
    void clearGameObjects();

public slots:
    void next();

signals:
    void refresh();

};

#endif // GAMEAREA_H
