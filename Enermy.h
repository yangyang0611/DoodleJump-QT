#ifndef ENERMY_H
#define ENERMY_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
class Enermy :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    struct point{
        int x,y;
    };

    Enermy(QGraphicsItem *parent=0);
    int random_num = rand() % 600;
    int random_num1 = rand() % 600;
    void addPlatform();
    virtual void paint();
public slots:
    void move();
private:
    point platform[20];
};

#endif // ENERMY_H
