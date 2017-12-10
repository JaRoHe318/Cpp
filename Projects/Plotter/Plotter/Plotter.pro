TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    animate.cpp \
    system.cpp \
    plotter.cpp \
    graph.cpp \
    point.cpp \
    translate.cpp

HEADERS += \
    animate.h \
    jvector.h\
    graph.h\
    const.h \
    system.h \
    plotter.h \
    point.h \
<<<<<<< HEAD
    jqueue.h
=======
    translate.h
>>>>>>> 9a3b3d39e7f06a9202b2d8f1c1d8842e397c5828

#WINDOWS
LIBS += -L"..\SFML-2.3.2\lib"
LIBS += -L"..\SFML-2.3.2\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.3.2\include"
DEPENDPATH += "..\SFML-2.3.2\include"
