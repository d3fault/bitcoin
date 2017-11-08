QT += core
QT -= gui

TARGET = Base58CheckTranscoderCli
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH *= $$system(pwd)/cli

SOURCES *= $$system(pwd)/cli/main.cpp

include(bitcoinbase58checktranscoder.pri)
