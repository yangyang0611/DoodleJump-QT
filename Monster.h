#ifndef MONSTER_H
#define MONSTER_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
class Monster :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Monster(QGraphicsItem *parent=0);
    int random_num = rand() % 500;
    int random_num1 = rand() % 500;
public slots:
};

#endif // MONSTER_H
