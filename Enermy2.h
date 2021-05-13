#ifndef ENERMY2_H
#define ENERMY2_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include"Enermy.h"
class Enermy2 : public Enermy
{
    Q_OBJECT
public:
    struct point{
        int x,y;
    };

    Enermy2(QGraphicsItem *parent=0);
    void addPlatform();
    int random_num2 = rand() % 700;
    int random_num3 = rand() % 700;
    virtual void paint();
public slots:
    void move();
private:
    point platform[20];
};

#endif // ENERMY2_H
