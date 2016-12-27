#ifndef BOSS_H
#define BOSS_H
#include "enemigo.h"
#include "rayo.h"
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QTimer>

class boss:public enemigo{
    Q_OBJECT
public:
    boss();
    ~boss(){
        Sboss->stop();
    }

public slots:
    void movimiento();
    void ataque();
private:
        QMediaPlayer *Sbala;
        QMediaPlayer *Sboss;
};

#endif // BOSS_H






