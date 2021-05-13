#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>
#include<QMediaPlayer>
#include"Hazard.h"
#include"Enermy.h"
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    int direction ;
    QString marks;
    void gameOver();
public slots:
    void spawn();
    void createHazard();
    void collidHazard();
    void createMonster();
    void collidMonster();
    void createHat();
    void collidHat();
    void createCoin();
    void collidCoin();
    void collidEnermy();
    void collidEnermy2();
    void bounce();
    void moveDown();
    void judge();
private slots:
    void hazardRemove();
private:
    QMediaPlayer * bulletSound;
    Player *player;
    QTimer *timer;
    Hazard *hazard;
    Enermy *enermy;
};

#endif // PLAYER_H
