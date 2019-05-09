TEMPLATE	= app
TARGET		= fileinformation

CONFIG		+= qt warn_on release
DEPENDPATH	= ../../include

QT          += widgets
HEADERS		= fileinformation.h
SOURCES		= fileinformation.cpp \
		  main.cpp
TRANSLATIONS  = fileinformation_zh.ts
