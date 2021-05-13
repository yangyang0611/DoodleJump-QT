#include "Game.h"
#include"Enermy.h"
#include"Enermy2.h"
#include"Hazard.h"
#include"Life.h"
#include<QGraphicsTextItem>
#include<QFont>
#include<QTimer>
#include<QBrush>
#include<QImage>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QMessageBox>
#include<QPushButton>
#include<QMessageBox>
#include<QApplication>
#include<QProcess>
#include<QKeyEvent>
#include<QLabel>

Game::Game(QWidget *parent)
{
    //create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create player
    player = new Player();
    player->setPos(420,300);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setPixmap(QPixmap(":/doodle_right.jpg"));
    player->setFocus();
    scene->addItem(player);


    //create score
    score = new Score();
    scene->addItem(score);

    //create life
    life = new Life();
    life->setPos(life->x(),life->y()+25);
    scene->addItem(life);

    //create enermy
    for(int i=0;i<10;i++){
        enermy = new Enermy();
        enermy->paint();
        scene->addItem(enermy);
    }

    //create enermy2
    for(int i=0;i<10;i++){
        enermy2 = new Enermy2();
        enermy2->paint();
        scene->addItem(enermy2);
    }

    //create hazard
    timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),player,SLOT(createHazard()));
    timer1->start(2000);

    //create monster
    timer2 = new QTimer();
    QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(createMonster()));
    timer2->start(2000);

    //create hat
    timer3 = new QTimer();
    QObject::connect(timer3,SIGNAL(timeout()),player,SLOT(createHat()));
    timer3->start(2000);

    //create Coin
    timer4 = new QTimer();
    QObject::connect(timer4,SIGNAL(timeout()),player,SLOT(createCoin()));
    timer4->start(2000);

    //play background music
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/doodle jump theme song.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    //exit button
    exitButton = new QPushButton(this);
    exitButton->setText("EXIT");
    exitButton->setGeometry(0,50,50,50);
    QObject::connect(exitButton,SIGNAL(clicked()),this,SLOT(exit()));

    //pause button
    pauseButton = new QPushButton(this);
    pauseButton->setText("PAUSE");
    pauseButton->setGeometry(0,100,50,50);
    QObject::connect(pauseButton,SIGNAL(clicked()),this,SLOT(pause()));

    //restart button
    restartButton = new QPushButton(this);
    restartButton->setText("RESTART");
    restartButton->setGeometry(0,150,80,50);
    QObject::connect(restartButton,SIGNAL(clicked()),this,SLOT(restart()));

    //resume button
    resumeButton = new QPushButton(this);
    resumeButton->setText("RESUME");
    resumeButton->setGeometry(0,200,80,50);
    resumeButton->setEnabled(false);
    QObject::connect(resumeButton,SIGNAL(clicked()),this,SLOT(resume()));

    //show marks
    //QLabel *label = new QLabel(this);
    //label->setGeometry(100,0,50,50);

    //label->setText(text);
    //label->setStyleSheet("color:red");

    show();
}

/*void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)   {
        player->setPixmap(QPixmap(":/doodle_up.jpg"));
        if(player->pos().y() > 300){
            player->setPos(player->x(), player->y()-50);


            for(int i=0;i<10;i++){
                enermy->setPos(enermy->x(), enermy->y()+10);
            }
        }
        if(player->pos().y() > 600){  // dispose enermy when exceed frame
             timer2->stop();
            scene->removeItem(player);
            delete this;
            QMessageBox::about(NULL,"Game Status","GAME OVER, YOUR MARKS IS " + score->getScore());
            QApplication::quit();
        }
    }
    else if(event->key() == Qt::Key_Down)   {
       if(player->pos().y() + 32 < 600){
           player->setPixmap(QPixmap(":/doodle_up.jpg"));
           player->setPos(player->x(), player->y()+10);
       }
       if(player->pos().y() > 600){  // dispose enermy when exceed frame
           scene->removeItem(player);
           delete this;
           QMessageBox::about(NULL,"Game Status","GAME OVER, YOUR MARKS IS "+ score->getScore());
           QApplication::quit();
           //game->timer1->stop();
       }
    }
    else if(event->key() == Qt::Key_Left)   {
        if(player->pos().x() > 0){     // meet bound
            player->setPixmap(QPixmap(":/doodle_left.jpg"));
            player->setPos(player->x()-10, player->y());//move to left
        }
        if(player->pos().x() < 0){
            player->setPos(player-> scene()->width()-x(), player->y());
            player->setPos(x()-10,y());
        }
        if(player->pos().y() > 600){  // dispose enermy when exceed frame
            scene->removeItem(player);
            delete this;
            QMessageBox::about(NULL,"Game Status","GAME OVER, YOUR MARKS IS "+ score->getScore());
            QApplication::quit();
        }
    }
    else if(event->key() == Qt::Key_Right)   {
        if(player->pos().x()  < 800){ // meet bounce
            player->setPixmap(QPixmap(":/doodle_right.jpg"));
            player->setPos(player->x()+10, player->y()); //move to right
        }
        if(player->pos().x() > 800) {
            player->setPos(player->scene()->width()-x(), player->y());
            player->setPos(player->x()+10, player->y());
        }
        if(player->pos().
                y() > 600){  // dispose enermy when exceed frame
            scene->removeItem(player);
            delete this;
            QMessageBox::about(NULL,"Game Status","GAME OVER, YOUR MARKS IS "+ score->getScore());
            QApplication::quit();

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
}*/

void Game::exit(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Game Status","Are u sure u want to quit?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
        QApplication::quit();
    else {
        QMessageBox::Close;
    }
}

void Game::pause()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Game Status","Are u sure u want to pause?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        timer1->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();
        resumeButton->setEnabled(true);
        music->pause();
    }
    else
        QMessageBox::Close;
}

void Game::resume(){
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Game Status","Are u sure u want to resume?",QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        timer1->start();
        timer2->start();
        timer3->start();
        timer4->start();
        music->play();
    }
    else {
        QMessageBox::Close;
    }
}

void Game::restart()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
}

void Game::hazardRemove(){
    if(hazard->hazardRemove == true){
        hazard = new Hazard();
        scene->addItem(hazard);
    }
}
