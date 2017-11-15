#ifndef CIRC_H
#define CIRC_H

#include "particle.h"

class Circ:public Particle{
public:
    Circ();
    Circ(int radius, sf::Vector2f pos);
    void UpdateV();
    void Draw(sf::RenderWindow& window);
private:
    sf::CircleShape _circ;
};

#endif // CIRC_H
