#ifndef RAYO_H
#define RAYO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class rayo:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    rayo();
public slots:
    void movimiento();
};

#endif // RAYO_H

