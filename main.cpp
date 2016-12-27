#include "game.h"
#include <QKeyEvent>
#include <QGraphicsScene>


extern puntaje *score;
extern vida *health;
int main(int argc,char *argv[])
{
    QApplication a(argc, argv);//funcion por defecto de aplicacion de QT
    //menu
    /*
    QGraphicsScene *cara=new QGraphicsScene();
    QGraphicsView *vista=new QGraphicsView(cara);

    //ocultando barras de desplazamiento
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->show();
    vista->setFixedSize(800,600);//limitando tamano de la vista
    cara->setSceneRect(0,0,800,600);
    cara->setBackgroundBrush(QBrush(QImage(":/imagenes/menu.png")));
    */

    game *juego=new game();
    juego->start();







    return a.exec();//retorna un tipo ejecutable del programa
}

