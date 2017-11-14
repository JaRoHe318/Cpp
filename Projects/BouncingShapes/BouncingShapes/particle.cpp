#include "particle.h"

Particle::Particle(){
    _x=r.Next(size,SCREEN_WIDTH-size);
    _y=r.Next(size,SCREEN_HEIGHT-size);

    sf::Vector2f vel= sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity

    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);


    sf::Color color=sf::Color(r_, g_, b_);
}


/*
 * Random r;

    int xpos = r.Next(radius,SCREEN_WIDTH-radius);
    int ypos = r.Next(radius,SCREEN_HEIGHT-radius);

    radius = r.Next(10,20);
    pointCount = r.Next(0,8);

    shape = sf::CircleShape(radius,pointCount);
    shape.setPosition(sf::Vector2f(xpos, ypos));

    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity

    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);
    sf::Color test = sf::Color(r_, g_, b_);

//    shape.setFillColor(sf::Color(r_, g_, b_));
     shape.setFillColor(test);
 * /
