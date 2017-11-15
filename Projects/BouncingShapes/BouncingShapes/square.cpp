#include "square.h"

Square::Square():Particle(){

}

Square::Square(sf::Vector2f side,sf::Vector2f position){
    _square = sf::RectangleShape(side);
    _square.setPosition(position);
}

void Square::UpdateV(){

}

void Square::Draw(sf::RenderWindow& window){
    window.draw(_square);
}
