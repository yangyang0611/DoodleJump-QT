#include"Hazard.h"
#include"Game.h"
#include"Player.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
extern Game *game;
Hazard::Hazard(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    //random create hazard
    setPixmap(QPixmap(":/blackhole.png"));
    setPos(random_num,random_num1);
}

void Hazard::move()  // nedd to inprove
{
    if(pos().y() < 600){
        setPos(x(), y()+10);
    }
    if(pos().y() > 600){  // dispose enermy when exceed frame

        hazardRemove = true;
        scene()->removeItem(this);
        delete this;
    }
}
