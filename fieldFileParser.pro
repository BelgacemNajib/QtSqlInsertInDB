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
    fieldfileloader.cpp \
    diefileloader.cpp \
    imgfileloader.cpp \
    stifileloader.cpp \
    hdrfileloader.cpp \
    spmfileloader.cpp \
    tbxfileloader.cpp

HEADERS += \
    fileloader.h \
    fieldfileloader.h \
    diefileloader.h \
    imgfileloader.h \
    stifileloader.h \
    hdrfileloader.h \
    spmfileloader.h \
    tbxfileloader.h
