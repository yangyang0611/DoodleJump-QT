#ifndef Life_H
#define Life_H
#include<QGraphicsTextItem>
#include<QMessageBox>

class Life: public QGraphicsTextItem
{
public:
    Life(QGraphicsItem *parent =0);
    void decrease();
    int getLife();
private:
    int life=3;
};

#endif // SCORE_H
