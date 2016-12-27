#ifndef VIDA_H
#define VIDA_H
#include <QGraphicsTextItem>

class vida:public QGraphicsTextItem{
public:
    vida();
    void decrementa(int i);
    int getvida(){return health;}
private:
    int health;
};

#endif // PUNTAJE_H
