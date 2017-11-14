TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    particle.cpp \
    random.cpp \
    rect.cpp \
    circ.cpp \
    hex.cpp \
    square.cpp

#WINDOWS
LIBS += -L"..\SFML-2.3.2\lib"
LIBS += -L"..\SFML-2.3.2\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.3.2\include"
DEPENDPATH += "..\SFML-2.3.2\include"

HEADERS += \
    random.h \
    jvector.h \
    vfunctions.h \
    particle.h \
    constants.h \
    rect.h \
    circ.h \
    hex.h \
    square.h
