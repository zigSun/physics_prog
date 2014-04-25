#-------------------------------------------------
#
# Project created by QtCreator 2014-04-13T14:46:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Physics
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    molecula.cpp

HEADERS  += widget.h \
    molecula.h \
    graph_widget.h

FORMS    += widget.ui
CONFIG +=qwt
