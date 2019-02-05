#-------------------------------------------------
#
# Project created by QtCreator 2018-08-20T22:00:05
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KalkProP2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES +=main.cpp \
    Model/forma.cpp \
    Model/punto.cpp \
    Model/poligono.cpp \
    Model/circonferenza.cpp \
    Model/triangolo.cpp \
    Model/quadrilatero.cpp \
    View/tabdialog.cpp \
    View/formetab.cpp \
    View/drawbox.cpp \
    Exception/eccezioni.cpp \
    Controller/datamanager.cpp


HEADERS +=Model/forma.h \
    Model/punto.h \
    Model/poligono.h \
    Model/circonferenza.h\
    Model/triangolo.h \
    Model/quadrilatero.h \
    View/tabdialog.h \
    View/formetab.h \
    View/drawbox.h \
    Exception/eccezioni.h \
    Controller/datamanager.h



