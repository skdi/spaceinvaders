#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <QGraphicsTextItem>

class puntaje:public QGraphicsTextItem{
public:
    puntaje(QGraphicsItem *objeto=0);
    void aumenta();
    int getscore();
//private:
    int score;
};

#endif // PUNTAJE_H
