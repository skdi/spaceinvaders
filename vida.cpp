#include "vida.h"
#include <QFont>

vida::vida():QGraphicsTextItem()
{
    health=5;
    //agregando texto a la pantalla
    setPlainText(QString("Vida:")+QString::number(health));//mostrara score:0
    setDefaultTextColor(Qt::red);//color
    setFont(QFont("times",16));//fuente
}

void vida::decrementa(int i){
    health-=i;
    setPlainText(QString("Vida:")+QString::number(health));//mostrara score:1
}
