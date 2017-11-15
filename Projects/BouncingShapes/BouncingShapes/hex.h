#ifndef HEX_H
#define HEX_H

#include "particle.h"

class Hex:public Particle{
public:
    Hex();
    void UpdateV();
    void Draw(sf::RenderWindow& window);
private:
    sf::CircleShape _hex;
};

#endif // HEX_H
