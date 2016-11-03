#include "jugador.h"
#include "disparo.h"
#include "enemigo.h"
#include <QKeyEvent>
#include <QGraphicsScene>


//movimiento del jugador
void jugador::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_Left){
        if(pos().x()>0+10)//limite para que el jugador no salga de la pantalla
            setPos(x()-10,y());
    }
    else if (evento->key()==Qt::Key_Right){
        if(pos().x()+rect().width()<scene()->width()-10)
            setPos(x()+10,y());
    }
    /*else if (evento->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (evento->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }*/

    /*else if (evento->key()==Qt::Key_Escape){
        scene->close();
    }*/
    else if (evento->key()==Qt::Key_Space){
        //creando bala
        disparo *bala=new disparo();
        //le doy la posicion (central) respecto a mi "jugador"
        bala->setPos(x()+(rect().width()/2 -5),y());
        scene()->addItem(bala);
    }
}

void jugador::spawn(){
    //creando un enemigo
    enemigo *enemy=new enemigo();
    scene()->addItem(enemy);

}


