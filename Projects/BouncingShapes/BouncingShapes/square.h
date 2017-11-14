#ifndef SQUARE_H
#define SQUARE_H

#include "particle.h"

class Square:public Particle{
public:
    Square();
    void UpdateV();
    void Draw(sf::RenderWindow& widnow);
private:
    sf::CircleShape _square;//yeah seriously - __ -
};

#endif // SQUARE_H
