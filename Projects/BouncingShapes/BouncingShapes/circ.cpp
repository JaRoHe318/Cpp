#include "circ.h"

Circ::Circ():Particle(){
    _circ=sf::CircleShape(getSize());
    cout<<"\nSize of Circ:"<<getSize();
    _circ.setPosition(getPos());
    _circ.setFillColor(sf::Color(100,200,254));

}
Circ::Circ(int radius,sf::Vector2f pos){
    _circ.setRadius(radius);
    _circ.setFillColor(sf::Color(100,200,254));
    _circ.setPosition(pos);
}

void Circ::UpdateV(){
    sf::Vector2f tester =Move(_circ.getPosition());
    _circ.move(tester);
}

void Circ::Draw(sf::RenderWindow& window){
    window.draw(_circ);
}
