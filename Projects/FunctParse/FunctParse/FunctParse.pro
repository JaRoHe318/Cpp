TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    error.cpp \
    functions.cpp \
    parser.cpp \
    variablelist.cpp


HEADERS += \
    constants.h \
    error.h \
    functions.h \
    parser.h \
    variablelist.h
