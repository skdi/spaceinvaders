#include "jugador.h"
#include <QKeyEvent>


//movimiento del jugador
void jugador::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if (evento->key()==Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if (evento->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (evento->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }
}

