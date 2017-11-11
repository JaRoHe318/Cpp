#ifndef ANIMATE_H
#define ANIMATE_H

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include "system.h"
#include "jvector.h"
#include "particle.h"

class animate{
public:
    animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();

private:
    sf::RenderWindow window;
    System system;                      //container for all the animated objects
};

#endif // ANIMATE_H
