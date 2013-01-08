#-------------------------------------------------
#
# Project created by QtCreator 2013-01-08T00:42:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = benchmark
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    renderthread.cpp

HEADERS  += widget.h \
    renderthread.h

FORMS    += widget.ui
