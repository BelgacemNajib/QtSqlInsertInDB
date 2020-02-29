QT += core
QT += sql
QT -= gui

TARGET = fieldFileParser
CONFIG += console
QMAKE_CFLAGS +=  -Wexpansion-to-defined
#CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    fileloader.cpp \
    fieldfileloader.cpp

HEADERS += \
    fileloader.h \
    fieldfileloader.h

