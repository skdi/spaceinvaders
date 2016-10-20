#ifndef JUGADOR_H
#define JUGADOR_H


#include <QGraphicsRectItem>


class jugador:public QGraphicsRectItem{
public :
        void keyPressEvent(QKeyEvent *evento);

};

#endif // JUGADOR_H
