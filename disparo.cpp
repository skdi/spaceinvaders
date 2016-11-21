#include "disparo.h"
#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>//para determinar el tipo del objeto ,lo uso en la colision de la bala y el enemigo
#include "puntaje.h"

extern puntaje *score;


disparo::disparo(){

    //dibujando la bala
    setRect(0,0,7,28);
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del disparo,y el movimiento
    tiempo->start(30);//delay para la bala
}

void disparo::movimiento(){
    //eliminando la bala y el enemigo
    QList<QGraphicsItem *>choque=collidingItems();//creo una lista de punteros de tipo item grafico
    for(int i=0,n=choque.size();i<n;++i){//recorro la lista y compruebo
        if(typeid(*(choque[i]))==typeid(enemigo)){//comprueba el tipo del objeto con el de enemigo
            score->aumenta();
            //borrar de la pantalla ambos items
            scene()->removeItem(choque[i]);
            scene()->removeItem(this);
            //eliminando su espacio de memoria
            delete choque[i];
            delete this;
            return;//para luego de ser elimininada
            //la bala salga de la funcion y no se ejecute el sig codigo
    }}
    //movimiento de la bala(subiendo)
    setPos(x(),y()-10);//actualizando movimiento de la bala (subiendo)
    //borrando las balas fuera de la pantalla
    if(pos().y()+ rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
