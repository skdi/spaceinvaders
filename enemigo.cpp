#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>

int p0=0,p1=0,aux;
enemigo::enemigo(){

    //iniciando posicion del enemigo
    setPos(p1+=50+p0,80);
    //else return;//detiene la creacion de los enemigos
    p0=50;
    //dibujando los enemigos
    setRect(0,0,50,80);
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del enemigo,y el movimiento
    tiempo->start(100);//delay
    //dejar de asignar posicion a los enemigos
    if(aux>8)
        //tiempo->disconnect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));

    aux+=1;
}

void enemigo::movimiento(){
    //movimiento del enemigo (bajando)
    setPos(x(),y()+1);//actualizando movimiento del enemigo (bajando)
    //borrando las enemigos fuera de la pantalla
    if(pos().y()+ rect().height()>600 || pos().x()+rect().width()>790){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
