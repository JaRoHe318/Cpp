#ifndef SQUARE_H
#define SQUARE_H

#include "particle.h"

class Square:public Particle{
public:
    Square();
    Square(sf::Vector2f side,sf::Vector2f position);
    void UpdateV();
    void Draw(sf::RenderWindow& window);
private:
//    sf::CircleShape _square;//yeah seriously - __ -
    sf::RectangleShape _square;
};

#endif // SQUARE_H
