#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
using namespace std;

#include "random.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

class Particle{
public:
    Particle();
    void UpdateV();
    void Draw(sf::RenderWindow& widnow);
private:
    sf::CircleShape shape;
    sf::Vector2f vel;

};

#endif // PARTICLE_H
