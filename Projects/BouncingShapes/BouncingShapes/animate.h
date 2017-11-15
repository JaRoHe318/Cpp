#ifndef ANIMATE_H
#define ANIMATE_H

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
    System system;
};

#endif // ANIMATE_H
