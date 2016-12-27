#include "boss.h"
#include <QTimer>
#include <QGraphicsScene>
#include "vida.h"

#include <QDebug>

extern vida *health;

boss::boss():enemigo(){

    //dibujando los enemigos
    setPixmap(QPixmap(":/imagenes/bossv2.png"));
    //sonidos a bala y boss

    Sbala=new QMediaPlayer();
    Sbala->setMedia(QUrl("qrc:/sonidos/rayo.mp3"));
    Sboss=new QMediaPlayer();
    Sboss->setMedia(QUrl("qrc:/sonidos/Sboss.mp3"));

    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del enemigo,y el movimiento
    connect(tiempo,SIGNAL(timeout()),this,SLOT(ataque()));
    tiempo->start(1000);//delay

    //sonido del boss
    if(Sboss->state()==QMediaPlayer::PlayingState)//si el sonido de la bala se esta reproduciendo
        Sboss->setPosition(0);//reinicio el sonido
    else if(Sboss->state()==QMediaPlayer::StoppedState)//si se ah reiniciado el sonido
        Sboss->play();//reproduce el sonido

}

void boss::movimiento(){
    //movimiento del boss
    setPos(x(),y()+5);//actualizando movimiento del boss
    //restringiendo al boss
    if(pos().y()>600 || pos().x()>790){
        scene()->removeItem(this);
        health->decrementa(5);
        delete this;
    }

}

void boss::ataque(){

    rayo *bala=new rayo();
    rayo *bala2=new rayo();
    //le doy la posicion (central) respecto al boss
    bala->setPos(x()+30,y()+80);
    bala2->setPos(x()+70,y()+80);
    bala->setScale(3);
    bala2->setScale(3);
    scene()->addItem(bala);
    scene()->addItem(bala2);

    //sonido de la bala
    if(Sbala->state()==QMediaPlayer::PlayingState)//si el sonido de la bala se esta reproduciendo
        Sbala->setPosition(0);//reinicio el sonido
    else if(Sbala->state()==QMediaPlayer::StoppedState)//si se ah reiniciado el sonido
        Sbala->play();//reproduce el sonido


}
