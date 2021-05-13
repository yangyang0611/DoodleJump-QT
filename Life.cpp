#include "Life.h"
#include"Game.h"
#include"Score.h"
#include<QFont>
#include<QLabel>
#include<QTimer>
#include"QApplication"
extern Game *game;
Life::Life(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setPlainText("");

    setPlainText(QString("Life: ") + QString::number(life));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Life::decrease(){

        life--;
        setPlainText(QString("Life: ") + QString::number(life));

    if (life<1){
        QLabel *label = new QLabel;
        QString text;
        text.setNum(Score().getScore());
        QMessageBox *messagebox1 = new QMessageBox();
        messagebox1->setText("Game Over, yours marks is " + text);
        messagebox1->exec();
        game->timer1->stop();
        game->timer2->stop();
        game->timer3->stop();
        game->timer4->stop();
        game->music->stop();

        QApplication::quit();
        }

}

int Life::getLife(){
    return life;
}
