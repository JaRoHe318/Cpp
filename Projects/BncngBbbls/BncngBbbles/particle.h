#ifndef PARTICLE_H
#define PARTICLE_H

#include "random.h"
#include <SFML/Graphics.hpp>



class Particle{
public:
    Particle();
    void UpdateV();
    void Draw(sf::RenderWindow& widnow);
private:
    sf::CircleShape shape;
    sf::Vector2f vel;
    const float SCREEN_WIDTH = 400;
    const float SCREEN_HEIGHT = 400;
};

#endif // PARTICLE_H
