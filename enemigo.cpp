#include "enemigo.h"
#include <QTimer>
#include <QGraphicsScene>

int p0=0,p1=0,aux=0,
c1=0,c0=0,x1=0,x0=0,
z1=0,z0=0;//variables auxiliares para la creacion de los enemigos

enemigo::enemigo(){
    int py=60;
    //iniciando posicion del enemigo
    setPos(p1+=50+p0,py);
    //else return;//detiene la creacion de los enemigos
    p0=50;
    //dibujando los enemigos
    setRect(0,0,50,60);
    //conectando al tiempo
    QTimer *tiempo=new QTimer();//creo un punto de la funcion respecto al tiempo
    connect(tiempo,SIGNAL(timeout()),this,SLOT(movimiento()));//conecto mi puntero con la señal,del enemigo,y el movimiento
    tiempo->start(100);//delay
    //reasignar posicion a los enemigos
    if(aux>=8&& aux<17){

        setPos(c1+=50+c0,-20);
        c0=50;
    }
    if(aux>=17&& aux<25){
        setPos(x1+=50+x0,-100);
        x0=50;
    }
    if(aux>=25&& aux<33){
        setPos(z1+=50+z0,-180);
        z0=50;
    }

    aux+=1;

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
