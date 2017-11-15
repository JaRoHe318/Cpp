#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

#include "random.h"
#include "constants.h"

class Particle{
public:
    Particle();
    sf::Vector2f Move(sf::Vector2f pos);
    sf::Vector2f getPos();
    sf::Vector2f getVel();
    sf::Color getColor();
    int getSize();



    virtual void UpdateV(){
    cout<<"UV: You're in the wrong\n";
    }
    virtual void Draw(sf::RenderWindow& window){
    cout<<"D: You're in the wrong\n";
    }

private:
    int _x;
    int _y;
    int size;
    sf::Vector2f _pos;//Initial Position
    sf::Vector2f _vel;//Initial Vel
    sf::Color _color;
    Random r;
};

#endif // PARTICLE_H
