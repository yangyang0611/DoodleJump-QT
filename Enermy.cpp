#include "Enermy.h"
#include"Game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QList>
#include<stdlib.h>
extern Game *game;
Enermy::Enermy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{

}

void Enermy::move()  // nedd to inprove
{
    setPos(x(), y()+10);
    if(pos().y() > 600){  // dispose enermy when exceed frame
        scene()->removeItem(this);
        delete this;
    }
}

void Enermy::addPlatform(){

}

void Enermy::paint()
{
    //random create enermy
    //draw platform
    setPixmap(QPixmap(":/platform_green.png"));
    setPos(random_num,random_num1);
    setTransformOriginPoint(50,50);
    setRotation(180);
}
