#include "particle.h"

Particle::Particle(){
    cout<<"In ParticleCon\n";

    size=r.Next(10,20);

    _x=r.Next(size,SCREEN_WIDTH-size);
    _y=r.Next(size,SCREEN_HEIGHT-size);


    cout<<"Position set at ("<<_x<<","<<_y<<")";
    _pos=sf::Vector2f(_x,_y);

    sf::Vector2f _vel= sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity

    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);

    sf::Color color=sf::Color(r_, g_, b_);
}

sf::Vector2f Particle::Move(sf::Vector2f pos){
    cout<<"In PMove\n";

    if ((pos.x)>=SCREEN_WIDTH-(2*size))
        _vel = sf::Vector2f(-1*_vel.x,1*_vel.y);
    if (pos.x<=0)
        _vel = sf::Vector2f(-1*_vel.x,1*_vel.y);
    if ((pos.y)>=SCREEN_HEIGHT-(2*size))
        _vel = sf::Vector2f(1*_vel.x,-1*_vel.y);
    if (pos.y<=0)
        _vel = sf::Vector2f(1*_vel.x,-1*_vel.y);

    return _vel;
}

sf::Vector2f Particle::getPos(){
    return _pos;
}
sf::Vector2f Particle::getVel(){
    return _vel;
}
sf::Color Particle::getColor(){
    return _color;
}

int Particle::getSize(){
    return size;
}

