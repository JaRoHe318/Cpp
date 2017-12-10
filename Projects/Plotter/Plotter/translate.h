#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "const.h"

class Translate{
public:
    Translate();
    Translate(double minX,double maxX,double minY, double maxY);
    void setPoint(double oldX,double oldY);
    void setPoint(sf::Vector2f oldPoint);
    sf::Vector2f getNewPoint();
private:
    double _newX;
    double _newY;
    sf::Vector2f newPoint;
};

#endif // TRANSLATE_H
