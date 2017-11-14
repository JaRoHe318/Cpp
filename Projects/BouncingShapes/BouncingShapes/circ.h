#ifndef CIRC_H
#define CIRC_H

#include "particle.h"

class Circ:public Particle{
public:
    Circ();
    void UpdateV();
    void Draw(sf::RenderWindow& widnow);
private:
    sf::CircleShape _circ;
};

#endif // CIRC_H
