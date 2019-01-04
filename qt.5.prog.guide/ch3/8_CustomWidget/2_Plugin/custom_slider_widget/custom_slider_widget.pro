CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(custom_slider_widgetplugin)
TEMPLATE    = lib

HEADERS     = custom_slider_widgetplugin.h
SOURCES     = custom_slider_widgetplugin.cpp
RESOURCES   = icons.qrc \
    resources.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(custom_slider_widget.pri)
