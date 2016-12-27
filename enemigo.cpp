#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>//lista para objetos en este caso tipo enemigo
#include <stdlib.h>//funcion random
#include "vida.h"

#include <QDebug>

extern vida *health;

enemigo::enemigo():QObject(),QGraphicsPixmapItem(){

    //iniciando posicion del enemigo
    int random=rand()%700;//700 num auxiliar ,ya que rand devuelve un numero muy grande
    setPos(random,0);
    //else return;//detiene la creacion de los enemigos

    //dibujando los enemigos
    setPixmap(QPixmap(":/imagenes/enemyv2.png"));
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del enemigo,y el movimiento
    tiempo->start(30);//delay

}

void enemigo::movimiento(){
    //movimiento del enemigo (bajando)
    setPos(x(),y()+1);//actualizando movimiento del enemigo (bajando)
    //borrando las enemigos fuera de la pantalla
    if(pos().y()>600 || pos().x()>790){
        scene()->removeItem(this);
        health->decrementa(1);
        /*if(health->health==0){
            scene()->clear();
        }*/
        delete this;
        //return;
    }
}
