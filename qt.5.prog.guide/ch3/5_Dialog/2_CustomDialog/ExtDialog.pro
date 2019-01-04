
QT       += core gui

TARGET = ExtDialog
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h
