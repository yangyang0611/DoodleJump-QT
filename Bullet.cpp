#include "Bullet.h"
#include"Enermy.h"
#include"Monster.h"
#include"Game.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>

extern Game * game;  // external global val name game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    //draw bullet
    setPixmap(QPixmap(":/bullet.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //bullet collided with enermy, dispose both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Monster)){
            //inc score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //fire bullet
    setPos(x(),y()-10);
    if(pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
