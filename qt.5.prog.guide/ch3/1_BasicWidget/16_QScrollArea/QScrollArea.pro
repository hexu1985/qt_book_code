
QT       += core gui

TARGET = QScrollArea
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

RESOURCES += \
    resources.qrc
