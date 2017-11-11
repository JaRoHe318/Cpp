#include "particle.h"

int radius;

Particle::Particle(){
    Random r;

    int xpos = r.Next(10,100);
    int ypos = r.Next(10,100);

    radius = r.Next(5,15);

    shape = sf::CircleShape(radius);
    shape.setPosition(sf::Vector2f(xpos, ypos));

    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity

    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);

    shape.setFillColor(sf::Color(r_, g_, b_));
}

void Particle::UpdateV(){
        shape.move(vel);

        sf::Vector2f pos = shape.getPosition();
        if ((pos.x)>=SCREEN_WIDTH-(2*radius))
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-(2*radius))
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
}

void Particle::Draw(sf::RenderWindow& window){
    window.draw(shape);
}
