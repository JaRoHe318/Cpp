#ifndef SYSTEM_H
#define SYSTEM_H

#include "const.h"
#include "plotter.h"

class System{
public:
    System();
    void Draw(sf::RenderWindow& window);
    void Step();
private:
};

#endif // SYSTEM_H
