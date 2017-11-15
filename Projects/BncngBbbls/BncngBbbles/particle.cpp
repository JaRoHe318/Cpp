#include "particle.h"

//int radius;

Particle::Particle(){
    Random r;


    radius = r.Next(10,20);

    int xpos = r.Next(radius,SCREEN_WIDTH-radius);
    int ypos = r.Next(radius,SCREEN_HEIGHT-radius);

    shape.setPosition(sf::Vector2f(xpos, ypos));

    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity

    pointCount = r.Next(0,8);

    shape = sf::CircleShape(radius,pointCount);

    int r_ = r.Next(0,255);
    int g_ = r.Next(0,255);
    int b_ = r.Next(0,255);
    sf::Color test = sf::Color(r_, g_, b_);
<<<<<<< HEAD

    //    shape.setFillColor(sf::Color(r_, g_, b_));
=======
>>>>>>> 9aa3f9e6305ec83dfb6f3221c6366a0b63dbcc9e
    shape.setFillColor(test);
    shape.setOrigin(0,0);
}

void Particle::UpdateV(){
    Random r;
<<<<<<< HEAD

=======
>>>>>>> 9aa3f9e6305ec83dfb6f3221c6366a0b63dbcc9e
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

<<<<<<< HEAD
    //        shape.rotate(1);
=======
    shape.rotate(1);
>>>>>>> 9aa3f9e6305ec83dfb6f3221c6366a0b63dbcc9e
}

void Particle::Draw(sf::RenderWindow& window){
    window.draw(shape);
}
