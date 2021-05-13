#ifndef GAME_H
#define GAME_H
#include<QMainWindow>
#include<QGraphicsView>
#include<QWidget>
#include<QGraphicsScene>
#include<QMessageBox>
#include"Player.h"
#include"Enermy.h"
#include"Enermy2.h"
#include"Score.h"
#include"Life.h"
#include"Hazard.h"
#include"Monster.h"
#include"Coin.h"
#include"Hat.h"



class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=0);
   //void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Life *life;
    Hazard *hazard;
    Monster *monster;
    Hat *hat;
    Coin *coin;
    Enermy *enermy;
    Enermy2 *enermy2;
    QMediaPlayer* music;

    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;



private:
    QPushButton *exitButton;
    QPushButton *pauseButton;
    QPushButton *restartButton;
    QPushButton *resumeButton;

signals:
    void clicked();

private slots:

      void hazardRemove();
      void exit();
      void pause();
      void restart();
      void resume();
};

#endif // GAME_H
