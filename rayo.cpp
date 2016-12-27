#include "rayo.h"
#include "jugador.h"
#include <QTimer>
#include "vida.h"
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern vida *health;

rayo::rayo():QObject(),QGraphicsPixmapItem(){

    //dibujando la bala
    setPixmap(QPixmap(":/imagenes/disparov2.png"));
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del disparo,y el movimiento
    tiempo->start(30);//delay para el rayo
}

void rayo::movimiento(){
    //eliminando la bala y el enemigo
    QList<QGraphicsItem *>choque=collidingItems();//creo una lista de punteros de tipo item grafico
    for(int i=0,n=choque.size();i<n;++i){//recorro la lista y compruebo
        if(typeid(*(choque[i]))==typeid(jugador)){//comprueba el tipo del objeto con el de enemigo
            //borrar de la pantalla ambos items
            health->decrementa(1);
            //eliminando su espacio de memoria
            scene()->removeItem(this);
            delete this;
            return;//para luego de ser elimininada
            //la bala salga de la funcion y no se ejecute el sig codigo
    }}
    //movimiento de la bala
    setPos(x(),y()+10);//actualizando movimiento de la bala
    //borrando las balas fuera de la pantalla
    if(pos().y()<0 || pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }
}

