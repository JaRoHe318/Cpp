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
    Point(double x, double y){
        _r=5;
        _pos=sf::Vector2f(x,y);
    }
    Point(double x, double y,int r){
        _r=r;
        _pos=sf::Vector2f(x,y);
    }


private:
//    double _x;
//    double _y;
    int _r;//radius
    sf::Vector2f _pos;
};

#endif // POINT_H
