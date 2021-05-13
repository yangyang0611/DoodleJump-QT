#include "Coin.h"
#include"Game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QList>
#include<stdlib.h>
extern Game *game;
Coin::Coin(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    //draw coin
    setPixmap(QPixmap(":/coin.png"));
    setPos(random_num,random_num1);
    setTransformOriginPoint(50,50);
    setRotation(180);
}

void Coin::move()
{
    setPos(x(), y()+10);
        // draw platform
    if(pos().y() > 600){  // dispose enermy when exceed frame
        scene()->removeItem(this);
        delete this;
    }
}
