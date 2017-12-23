TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jtoken.cpp \
    integer.cpp \
    op.cpp \
    rpn.cpp \
    double.cpp \
    funct.cpp

HEADERS += \
    jstack.h \
    jqueue.h \
    jtoken.h \
    consts.h \
    integer.h \
    op.h \
    rpn.h \
    double.h \
    funct.h
