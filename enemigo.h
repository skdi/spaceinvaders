#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QObject>


class enemigo:public QObject,public QGraphicsRectItem{
    Q_OBJECT//macro de tipo objeto para el uso de esta funcion
public:
    enemigo();
public slots:
    void movimiento();
};



#endif // ENEMIGO_H
