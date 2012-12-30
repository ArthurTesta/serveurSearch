#-------------------------------------------------
#
# Project created by QtCreator 2012-11-18T13:09:45
#
#-------------------------------------------------

QT       += core gui \
         network    \
         sql
TARGET = serveurFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindowservfinal.cpp \
    serveurtcp.cpp \
    media.cpp \
    medialist.cpp \
    uploadthread.cpp \
    protocol.cpp \
    tools.cpp

HEADERS  += mainwindowservfinal.h \
    serveurtcp.h \
    media.h \
    medialist.h \
    uploadthread.h \
    protocol.h \
    tools.h \
    exception.h

FORMS    += mainwindowservfinal.ui
