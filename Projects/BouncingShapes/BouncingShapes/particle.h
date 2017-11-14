#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

#include "random.h"
#include "constants.h"

class Particle{
public:
    Particle();



    virtual void UpdateV(){
    cout<<"UV: You're in the wrong\n";
    }
    virtual void Draw(sf::RenderWindow& widnow){
    cout<<"D: You're in the wrong\n";
    }

private:
    int _x;
    int _y;
    int size;
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::Color color;
    Random r;
};

#endif // PARTICLE_H
