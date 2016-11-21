#include "vida.h"
#include <QFont>

vida::vida(QGraphicsItem *objeto):QGraphicsTextItem()
{
    health=5;
    //agregando texto a la pantalla
    setPlainText(QString("Vida:")+QString::number(health));//mostrara score:0
    setDefaultTextColor(Qt::red);//color
    setFont(QFont("times",16));//fuente
}



void vida::decrementa(){
    health-=1;
    setPlainText(QString("Vida:")+QString::number(health));//mostrara score:1
}

int vida::getvida(){
    return health;
}
