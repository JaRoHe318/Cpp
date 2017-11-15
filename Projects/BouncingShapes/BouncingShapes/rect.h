#ifndef RECT_H
#define RECT_H

#include "particle.h"

class Rect:public Particle{
public:
    Rect();
    void UpdateV();
    void Draw(sf::RenderWindow& window);
private:
    sf::RectangleShape _rect;
};

#endif // RECT_H
