#CONFIG      += designer plugin debug_and_release
#TARGET      = $$qtLibraryTarget(custom_cpu_widgetplugin)
#TEMPLATE    = lib

#HEADERS     = custom_cpu_widgetplugin.h
#SOURCES     = custom_cpu_widgetplugin.cpp
#RESOURCES   = icons.qrc
#LIBS        += -L.

#target.path = $$[QT_INSTALL_PLUGINS]/designer
#INSTALLS    += target

#include(custom_cpu_widget.pri)

#///////////////////////////////////////////////////////////
QT          += widgets designer

CONFIG      += plugin release
TARGET      = $$qtLibraryTarget(custom_cpu_widgetplugin)
TEMPLATE    = lib

HEADERS     = custom_cpu_widgetplugin.h
SOURCES     = custom_cpu_widgetplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L.

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(custom_cpu_widget.pri)


