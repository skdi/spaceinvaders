#ifndef GAME_H
#define GAME_H

#include "jugador.h"
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "puntaje.h"
#include "vida.h"
#include <QMediaPlayer>
#include <Qimage>
#include <QBrush>
#include "boss.h"


class game
{
public:
    game();
    void start();
};

#endif // GAME_H
