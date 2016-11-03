#include "disparo.h"
#include <QTimer>
#include <QGraphicsScene>

disparo::disparo(){

    //dibujando la bala
    setRect(0,0,7,28);
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del disparo,y el movimiento
    tiempo->start(30);//delay para la bala
}

void disparo::movimiento(){
    //movimiento de la bala(subiendo)
    setPos(x(),y()-10);//actualizando movimiento de la bala (subiendo)
    //borrando las balas fuera de la pantalla
    if(pos().y()+ rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
