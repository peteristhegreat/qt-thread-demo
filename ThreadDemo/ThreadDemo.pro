#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T21:20:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThreadDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    worker.cpp \
    controller.cpp \
    processutils.cpp

HEADERS  += mainwindow.h \
    worker.h \
    controller.h \
    processutils.h

FORMS    += mainwindow.ui
