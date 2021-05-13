#ifndef COIN_H
#define COIN_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
class Coin :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Coin(QGraphicsItem *parent=0);
    int random_num = rand() % 600;
    int random_num1 = rand() % 600;
    void move();
public slots:
};

#endif // COIN_H
