#-------------------------------------------------
#
# Project created by QtCreator 2018-07-10T17:22:52
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += xml
QT       += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mamTools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    comobject.cpp

HEADERS  += mainwindow.h \
    comobject.h

RESOURCES += \
    rs.qrc

RC_ICONS = mamtool.ico
