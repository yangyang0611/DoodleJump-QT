#ifndef HAZARD_H
#define HAZARD_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
class Hazard :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hazard(QGraphicsItem *parent=0);
    int random_num = rand() % 400;
    int random_num1 = rand() % 400;
    void move();
    bool hazardRemove = false;

public slots:
};

#endif // ENERMY_H
