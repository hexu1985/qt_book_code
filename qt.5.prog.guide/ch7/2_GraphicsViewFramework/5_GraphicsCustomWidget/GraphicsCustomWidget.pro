
QT       += core gui

TARGET = GraphicsCustomWidget
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += main.cpp \
    CustomItem.cpp

HEADERS  += \
    CustomItem.h

RESOURCES += \
    resources.qrc
