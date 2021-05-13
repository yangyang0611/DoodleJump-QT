#include "Player.h"
#include "Bullet.h"
#include"Enermy.h"
#include"Enermy2.h"
#include"Life.h"
#include"Hazard.h"
#include"Monster.h"
#include"Hat.h"
#include"Coin.h"
#include"Game.h"
#include"Score.h"
#include<QDebug>
#include<QTimer>
#include<QKeyEvent>
#include<QGraphicsScene>
#include<QMessageBox>
#include<QApplication>
#include<QLabel>
extern Game *game;
Player::Player(QGraphicsItem *parent) :QGraphicsPixmapItem (parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/bullet sound.mp3"));

    // judge colliding
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(collidHazard()));
    timer->start(50);

    QTimer *timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(collidMonster()));
    timer1->start(50);

    QTimer *timer2 = new QTimer();
    connect(timer2,SIGNAL(timeout()),this,SLOT(collidCoin()));
    timer2->start(50);

    QTimer *timer3 = new QTimer();
    connect(timer3,SIGNAL(timeout()),this,SLOT(collidHat()));
    timer3->start(50);

    QTimer *timer4 = new QTimer();
    connect(timer4,SIGNAL(timeout()),this,SLOT(collidEnermy()));
    timer4->start(50);

    QTimer *timer5 = new QTimer();
    connect(timer5,SIGNAL(timeout()),this,SLOT(collidEnermy2()));
    timer5->start(50);

    /*QTimer *timer6 = new QTimer();
    connect(timer6,SIGNAL(judge()),this,SLOT(moveDown()));
    timer6->start(50);*/


    //marks.setNum(Score().getScore());
}

void Player::timerEvent(QTimerEvent *event){
    //if(event->timerId() == timerId && gamePause){


    //if(life == 0){


}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)   {
        direction = 8;
        setPixmap(QPixmap(":/doodle_up.jpg"));
        judge();
        if(pos().y() > 300){
            setPos(x(),y()-50);
        }
        if(pos().y() > 600){  // dispose enermy when exceed frame
            scene()->removeItem(this);
            delete this;
            gameOver();
        }
    }
    else if(event->key() == Qt::Key_Down)   {
       if(pos().y() + 32 < 600){
           direction = 2;
           setPixmap(QPixmap(":/doodle_up.jpg"));
           setPos(x(),y()+10);
       }
       if(pos().y() > 600){  // dispose enermy when exceed frame
           scene()->removeItem(this);
           delete this;
           gameOver();
       }
    }
    else if(event->key() == Qt::Key_Left)   {
        if(pos().x() > 0){     // meet bound
            direction = 4;
            setPixmap(QPixmap(":/doodle_left.jpg"));
            setPos(x()-10,y());//move to left
        }
        if(pos().x() < 0){
            setPos(800-x(),y());
            setPos(x()-10,y());
        }
        if(pos().y() > 600){  // dispose enermy when exceed frame
            scene()->removeItem(this);
            delete this;
            gameOver();
        }
    }
    else if(event->key() == Qt::Key_Right)   {
        if(pos().x()  < 800){ // meet bounce
            direction = 6;
            setPixmap(QPixmap(":/doodle_right.jpg"));
            setPos(x()+10,y()); //move to right
        }
        if(pos().x() > 800) {
            setPos(800-x(),y());
            setPos(x()+10,y());
        }
        if(pos().y() > 600){  // dispose enermy when exceed frame
            scene()->removeItem(this);
            delete this;
            gameOver();
        }
    }
    else if(event->key() == Qt::Key_Space)   {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        setPixmap(QPixmap(":/doodle_up.jpg"));

        //play bullet sound
        if(bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if(bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }
    }
    else if(event->key() == Qt::Key_0)   {
        gameOver();
    }
}

void Player::gameOver()
{
    QString text;
 text.setNum(game->score->getScore());
    //text.setNum(Score().getScore());
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

void Player::judge(){
    if(pos().y() < 300 && pos().y() > 0){  // everyone go down
        setPos(x(),y()-50);

    }
}

void Player::hazardRemove()
{
    if(hazard->hazardRemove == true){

    }
    else {
        return;
    }
}
void Player::collidHazard()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Hazard)){
            //decrease life
            game->life->decrease();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void Player::collidMonster(){
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Monster)){
            //decrease life
            game->life->decrease();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void Player::collidCoin(){
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Coin)){
            //score++
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void Player::collidEnermy()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Enermy)){
            // do something
            setPos(x(), colliding_items[i]->y());
            return;
        }
    }
}

void Player::collidEnermy2()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Enermy2)){
            // do something
            QTimer *timer6 = new QTimer();
            connect(timer6,SIGNAL(timeout()),this,SLOT(bounce()));
            timer6->start(50);

            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void Player::collidHat(){
    QList<QGraphicsItem*> colliding_items = collidingItems();  // collid item = hazard
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid (*(colliding_items[i])) == typeid (Hat)){
            //do something
            setPos(x(),y()-100);

            //remove them both
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
    }
}

void Player::spawn()  // need to changed
{

}

void Player::createHazard(){
    Hazard *hazard = new Hazard();
    scene()->addItem(hazard);
}

void Player::createMonster(){
    Monster *monster = new Monster();
    scene()->addItem(monster);
}

void Player::createHat(){
    Hat *hat = new Hat();
    scene()->addItem(hat);
}

void Player::createCoin(){
    Coin *coin = new Coin();
    scene()->addItem(coin);
}

void Player::bounce(){
   setPos(x(),y()+10);
}

void Player::moveDown(){

    game->enermy->move();
    game->enermy2->move();
}
