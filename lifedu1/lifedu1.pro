#-------------------------------------------------
#
# Project created by QtCreator 2021-06-23T15:56:40
#
#-------------------------------------------------

QT       += core gui

QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lifedu1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    home.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    home.h \
    login.h \
    db.h

FORMS    += mainwindow.ui \
    home.ui \
    login.ui

DISTFILES += \
    ../../Desktop/LIFEDU.png

