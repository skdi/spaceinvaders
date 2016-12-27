#ifndef JUGADOR_H
#define JUGADOR_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>


class jugador:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public :
        jugador(QGraphicsItem * variable=0);
        void keyPressEvent(QKeyEvent *evento);//tipoparticular de funcion para la recepcion de teclas
public slots:
        void spawn();
        void spawn2();
private:
        QMediaPlayer *Sbala;


};

#endif // JUGADOR_H
