#include "puntaje.h"
#include <QFont>

puntaje::puntaje(QGraphicsItem *objeto):QGraphicsTextItem()
{
    score=0;
    //agregando texto a la pantalla
    setPlainText(QString("Score:")+QString::number(score));//mostrara score:0
    setDefaultTextColor(Qt::white);//color
    setFont(QFont("times",16));//fuente
}

void puntaje::aumenta(int i=10){
    score+=i;
    setPlainText(QString("Score:")+QString::number(score));//mostrara score:10
}

int puntaje::getscore(){
    return score;
}
