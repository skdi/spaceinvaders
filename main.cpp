#include "jugador.h"
#include <QMainWindow>

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>



int main(int argc,char *argv[])
{
    QApplication a(argc, argv);

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
    vista->show();

    return a.exec();
}
