#include "Hat.h"
#include"Game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
extern Game *game;
Hat::Hat(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    //draw hat
    setPixmap(QPixmap(":/hat.png"));
    setPos(random_num,random_num1);
    setTransformOriginPoint(50,50);
    setRotation(180);
}
