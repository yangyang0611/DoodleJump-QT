#ifndef HAT_H
#define HAT_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
class Hat :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hat(QGraphicsItem *parent=0);
    int random_num = rand() % 700;
    int random_num1 = rand() % 700;
public slots:
};

#endif // ENERMY_H
