#include"Monster.h"
#include"Game.h"
#include"Player.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QList>
#include<stdlib.h>
extern Game *game;
Monster::Monster(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem (parent)
{
    //draw MONSTER
    setPixmap(QPixmap(":/doodle_monsters.png"));
    setPos(random_num,random_num1);
}


