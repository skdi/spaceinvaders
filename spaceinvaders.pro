#-------------------------------------------------
#
# Project created by QtCreator 2016-10-19T20:17:25
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spaceinvaders
TEMPLATE = app


SOURCES += main.cpp\
        jugador.cpp \
    disparo.cpp \
    enemigo.cpp \
    puntaje.cpp \
    vida.cpp \
    boss.cpp \
    rayo.cpp \
    game.cpp

HEADERS  += jugador.h \
    disparo.h \
    enemigo.h \
    puntaje.h \
    vida.h \
    boss.h \
    rayo.h \
    game.h

FORMS    +=

RESOURCES += \
    res.qrc

DISTFILES +=
