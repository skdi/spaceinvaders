#ifndef VIDA_H
#define VIDA_H
#include <QGraphicsTextItem>

class vida:public QGraphicsTextItem{
public:
    vida(QGraphicsItem *objeto=0);
    void decrementa();
    int getvida();
private:
    int health;
};

#endif // PUNTAJE_H
