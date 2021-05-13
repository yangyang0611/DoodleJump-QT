#include "Enermy2.h"
#include"Game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QList>
#include<stdlib.h>
extern Game *game;
Enermy2::Enermy2(QGraphicsItem *parent)
{

}

void Enermy2::move()  // nedd to inprove
{
    setPos(x(), y()+10);
        // draw platform
    if(pos().y() > 600){  // dispose enermy when exceed frame
        scene()->removeItem(this);
        delete this;
    }
}

void Enermy2::addPlatform(){

}

void Enermy2::paint(){
    //random create enermy
    //draw platform
    setPixmap(QPixmap(":/platform_wood.png"));
    setPos(random_num2,random_num3);
    setTransformOriginPoint(50,50);
    setRotation(180);
}
