#include "game.h"

puntaje *score;
vida *health;
game::game(){

}

void game::start(){



    //creando el scenario
    QGraphicsScene *scene=new QGraphicsScene();


    //creando item 1 jugador
    jugador *jugado=new jugador();
    jugado->setScale(2);

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

    //poniendo el background al screen
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/bgwa.jpg")));

    //posicion inicial en el medio ,abajo
    jugado->setPos(vista->width()/2,vista->height()-104);

    //spawn de enemigos
    QTimer *tiempo=new QTimer();
    QObject::connect(tiempo,SIGNAL(timeout()),jugado,SLOT(spawn()));

    QTimer *tiempo2=new QTimer();
    tiempo2->start(30000);//delay creacion del boss
    QObject::connect(tiempo2,SIGNAL(timeout()),jugado,SLOT(spawn2()));
    tiempo->start(1000);//delay de creacion del enemigo

    //agregando puntaje
    score=new puntaje();
    scene->addItem(score);
    //agregando vida
    health=new vida();
    health->setPos(0,20);
    scene->addItem(health);

    //musica y sonidos
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sonidos/bgsoundre.mp3"));
    //sonido de la bala
    if(music->state()==QMediaPlayer::PlayingState)//si el sonido de la bala se esta reproduciendo
        music->setPosition(0);//reinicio el sonido
    else if(music->state()==QMediaPlayer::StoppedState)//si se ah reiniciado el sonido
        music->play();//reproduce el sonido


}


