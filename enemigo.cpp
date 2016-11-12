#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>//lista para objetos en este caso tipo enemigo
#include <stdlib.h>//funcion random

#include <QDebug>

enemigo::enemigo():QObject(),QGraphicsRectItem(){

    //iniciando posicion del enemigo
    int random=rand()%700;//700 num auxiliar ,ya que rand devuelve un numero muy grande
    setPos(random,0);
    //else return;//detiene la creacion de los enemigos

    //dibujando los enemigos
    setRect(0,0,50,60);
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del enemigo,y el movimiento
    tiempo->start(30);//delay

}

void enemigo::movimiento(){
    //movimiento del enemigo (bajando)
    setPos(x(),y()+1);//actualizando movimiento del enemigo (bajando)
    //borrando las enemigos fuera de la pantalla
    if(pos().y()+ rect().height()>600 || pos().x()+rect().width()>790){
        scene()->removeItem(this);
        delete this;
        //return;
    }
}
