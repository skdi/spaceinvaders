#ifndef JUGADOR_H
#define JUGADOR_H

#include <QMainWindow>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

class jugador:public QGraphicsRectItem{
public :
        void keyPressEvent(QKeyEvent *evento);

};

#endif // JUGADOR_H
