#-------------------------------------------------
#
# Project created by QtCreator 2014-02-26T17:51:32
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Viajes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    admin1.cpp \
    cliente.cpp \
    aeropuerto.cpp \
    conexion.cpp \
    TinyXml/tinystr.cpp \
    TinyXml/tinyxml.cpp \
    TinyXml/tinyxmlerror.cpp \
    TinyXml/tinyxmlparser.cpp

HEADERS  += mainwindow.h \
    admin1.h \
    cliente.h \
    aeropuerto.h \
    conexion.h \
    TinyXml/tinystr.h \
    TinyXml/tinyxml.h

FORMS    += mainwindow.ui \
    admin1.ui \
    cliente.ui

RESOURCES += \
    application.qrc
