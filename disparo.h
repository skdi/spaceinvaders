#ifndef DISPARO_H
#define DISPARO_H
#include <QGraphicsRectItem>
#include <QObject>


class disparo:public QObject,public QGraphicsRectItem{
    Q_OBJECT//macro de tipo objeto para el uso de esta funcion
public:
    disparo();
public slots:
    void movimiento();
};

#endif // DISPARO_H
