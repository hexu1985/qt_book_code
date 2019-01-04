#-------------------------------------------------
#
# Project created by QtCreator 2011-05-11T10:22:45
#
#-------------------------------------------------

QT       += core gui

TARGET = export_widget_example
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h \
    custom_cpu_widget.h \
    custom_slider_widget.h

FORMS    += widget.ui

LIBS += /root/libcustom_cpu_widgetplugin.so
LIBS += /root/libcustom_slider_widgetplugin.so

RESOURCES +=
