#ifndef ANIMATE_H
#define ANIMATE_H

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "system.h"

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

    const float SCREEN_WIDTH = 400;
    const float SCREEN_HEIGHT = 400;
};

#endif // ANIMATE_H
