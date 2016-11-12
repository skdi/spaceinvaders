#include "jugador.h"
#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "puntaje.h"



int main(int argc,char *argv[])
{
    QApplication a(argc, argv);//funcion por defecto de aplicacion de QT

    //creando el scenario
    QGraphicsScene *scene=new QGraphicsScene();

    //creando item 1 jugador
    jugador *jugado=new jugador();
    jugado->setRect(0,0,80,100);

    //agregando el item a la pantalla
    scene->addItem(jugado);

    //actualizando posicion
    jugado->setFlag(QGraphicsItem::ItemIsFocusable);
    jugado->setFocus();


    //vista
    QGraphicsView *vista=new QGraphicsView(scene);

    //ocultando barras de desplazamiento
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->show();
    vista->setFixedSize(800,600);//limitando tamano de la vista
    scene->setSceneRect(0,0,800,600);
    //posicion inicial en el medio ,abajo
    jugado->setPos(vista->width()/2 - (jugado->rect().width())/2,vista->height()-jugado->rect().height()-10);

    //spawn de enemigos
    QTimer *tiempo=new QTimer();
    QObject::connect(tiempo,SIGNAL(timeout()),jugado,SLOT(spawn()));
    tiempo->start(1000);//delay de creacion del enemigo
    //agregando puntaje
    puntaje *score=new puntaje();
    scene->addItem(score);

    return a.exec();//retorna un tipo ejecutable del programa
}
