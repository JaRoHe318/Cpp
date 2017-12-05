TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jtoken.cpp \
    integer.cpp \
    op.cpp \
    double.cpp \
    funct.cpp \
    sortingyard.cpp

HEADERS += \
    jstack.h \
    jqueue.h \
    jtoken.h \
    consts.h \
    integer.h \
    op.h \
    double.h \
    funct.h \
    sortingyard.h
