#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T17:59:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Percolation
TEMPLATE = app
QMAKE_CXXFLAGS +=-std=c++11

SOURCES += main.cpp\
        MainWindow.cpp \
    Afficheur.cpp \
    Percolateur.cpp \
    Site.cpp \
    WeightedQuickUnionUF.cpp

HEADERS  += MainWindow.h \
    Afficheur.h \
    Percolateur.h \
    Site.h \
    WeightedQuickUnionUF.h

FORMS    += MainWindow.ui

OTHER_FILES += \
    Spécifications.txt
