TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animate.cpp \
    system.cpp \
    graph.cpp \
    tokenizer.cpp \
    jtoken.cpp \
    double.cpp \
    integer.cpp \
    op.cpp \
    funct.cpp \
    sortingyard.cpp \
    rpn.cpp \
    plotter.cpp

HEADERS += \
    animate.h \
    consts.h \
    system.h \
    graph.h \
    tokenizer.h \
    jtoken.h \
    double.h \
    integer.h \
    op.h \
    funct.h \
    jqueue.h \
    sortingyard.h \
    rpn.h \
    jstack.h \
    jvector.h \
    point.h \
    plotter.h

#WINDOWS
LIBS += -L"..\SFML-2.3.2\lib"
LIBS += -L"..\SFML-2.3.2\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.3.2\include"
DEPENDPATH += "..\SFML-2.3.2\include"
