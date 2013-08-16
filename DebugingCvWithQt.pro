#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T11:03:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DebugingCvWithQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cvdebugwindow.cpp \
    cvdebugsystem.cpp

HEADERS  += mainwindow.h \
    cvdebugwindow.h \
    cvdebugsystem.h

FORMS    += mainwindow.ui \
    cvdebugwindow.ui

PKGCONFIG += opencv

CONFIG += link_pkgconfig
