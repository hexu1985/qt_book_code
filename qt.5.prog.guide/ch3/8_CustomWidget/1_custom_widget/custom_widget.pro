
QT       += core gui

TARGET = custom_widget
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        widget.cpp \
    custom_cpu_widget.cpp \
    custom_slider_widget.cpp

HEADERS  += widget.h \
    custom_cpu_widget.h \
    custom_slider_widget.h

RESOURCES += \
    resources.qrc
