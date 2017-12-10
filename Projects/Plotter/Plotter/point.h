#ifndef POINT_H
#define POINT_H

#include "const.h"

/*What I want to do is a Vector of points
 * so that when I call my Plotter, it goes
 * through the vector and plots each one.
 *
 * So then first the plotter gives a domain of
 * values.  Which will call RPN for each one,
 * and as each one is getting called, it gives
 * back the position (x,y) in either the form
 * of Vector2f or in x,y
 *
 * May not give user option to set radius?
 *
*/
class Point{
public:
    Point(){}
    Point(sf::Vector2f pos, int r){
        _r=r;
        _pos=pos;
    }
<<<<<<< HEAD
    Point(double x, double y){
        _r=5;
        _pos=sf::Vector2f(x,y);
    }
=======
>>>>>>> 9a3b3d39e7f06a9202b2d8f1c1d8842e397c5828
    Point(double x, double y,int r){
        _r=r;
        _pos=sf::Vector2f(x,y);
    }
<<<<<<< HEAD
=======
    void setPos(double x,double y){
        _point.setPosition(sf::Vector2f(x,y));
    }
    void setPos(sf::Vector2f newPos){
        _point.setPosition(newPos);
    }

    void Draw(sf::RenderWindow& window){
        window.draw(_point);
    }
>>>>>>> 9a3b3d39e7f06a9202b2d8f1c1d8842e397c5828


private:
//    double _x;
//    double _y;
    int _r;//radius
    sf::Vector2f _pos;
<<<<<<< HEAD
};

=======
    sf::CircleShape _point;
};






>>>>>>> 9a3b3d39e7f06a9202b2d8f1c1d8842e397c5828
#endif // POINT_H
