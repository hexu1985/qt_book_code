#-------------------------------------------------
#
# Project created by QtCreator 2013-02-25T17:13:17
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3_SimpleSAX
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    saxParser.cpp

HEADERS  += widget.h \
    saxParser.h

OTHER_FILES += \
    books.xml
