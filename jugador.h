#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>


class jugador:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public :
        void keyPressEvent(QKeyEvent *evento);
public slots:
        void spawn();


};

#endif // JUGADOR_H
