#include "puntaje.h"
#include <QFont>

puntaje::puntaje(QGraphicsItem *objeto):QGraphicsTextItem()
{
    score=0;
    //agregando texto a la pantalla
    setPlainText(QString("Score:")+QString::number(score));//mostrara score:0
    setDefaultTextColor(Qt::blue);//color
    setFont(QFont("times",16));//fuente
}

void puntaje::aumenta(){
    score+=10;
    setPlainText(QString("Score:")+QString::number(score));//mostrara score:1
}

int puntaje::getscore(){
    return score;
}
