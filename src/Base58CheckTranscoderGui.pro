#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T22:36:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Base58CheckTranscoderGui
TEMPLATE = app

INCLUDEPATH *= $$system(pwd)/gui

HEADERS  *= $$system(pwd)/gui/base58checktranscoderwidget.h

SOURCES *= $$system(pwd)/gui/main.cpp \
        $$system(pwd)/gui/base58checktranscoderwidget.cpp

include(bitcoinbase58checktranscoder.pri)
