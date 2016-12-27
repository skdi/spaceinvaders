#include "jugador.h"
#include "disparo.h"
#include "enemigo.h"
#include "boss.h"
#include <QKeyEvent>
#include <QGraphicsScene>


//movimiento del jugador
jugador::jugador(QGraphicsItem *variable):QGraphicsPixmapItem(variable){
    Sbala=new QMediaPlayer();
    Sbala->setMedia(QUrl("qrc:/sonidos/disparo1.mp3"));

    setPixmap(QPixmap(":/imagenes/playerv2.png"));

}

void jugador::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_Left){
        if(pos().x()>0+10)//limite para que el jugador no salga de la pantalla
            setPos(x()-10,y());
    }
    else if (evento->key()==Qt::Key_Right){
        if(pos().x()<scene()->width()-10)
            setPos(x()+10,y());
    }
    else if (evento->key()==Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if (evento->key()==Qt::Key_Down){
        setPos(x(),y()+10);
    }

    else if (evento->key()==Qt::Key_Escape){
        scene()->setBackgroundBrush(QBrush(QImage(":/imagenes/menu.png")));
    }
    else if (evento->key()==Qt::Key_Space){
        //creando bala
        disparo *bala=new disparo();
        //le doy la posicion (central) respecto a mi "jugador"
        bala->setPos(x()+25,y()-30);
        bala->setScale(0.55);
        bala->setOpacity(7);
        scene()->addItem(bala);

        //sonido de la bala
        if(Sbala->state()==QMediaPlayer::PlayingState)//si el sonido de la bala se esta reproduciendo
            Sbala->setPosition(0);//reinicio el sonido
        else if(Sbala->state()==QMediaPlayer::StoppedState)//si se ah reiniciado el sonido
            Sbala->play();//reproduce el sonido
    }
}

void jugador::spawn(){
    //creando un enemigo
    enemigo *enemy=new enemigo();
    enemy->setScale(2);
    scene()->addItem(enemy);

}

void jugador::spawn2(){
    //creando el boss
    boss *jefe=new boss();
    //jefe->setPos(400,y()+100);
    scene()->addItem(jefe);

}

