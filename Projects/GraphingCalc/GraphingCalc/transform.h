#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "consts.h"

class Transform{
public:
    Transform();
    Transform(double domainMin, double domainMax, double rangeMin, double rangeMax);
    void setDomain(double domainMin, double domainMax);
    void setPoint(double oldX,double oldY);
    void setPoint(sf::Vector2f oldPoint);
    void zoomPoint(double oldX, double oldY, char how);
    sf::Vector2f getNewPoint();
private:
    double _domainMin, _domainMax;
    double _domainTotal;
    double _rangeMin, _rangeMax;
    double _rangeTotal;
    double _newX, _newY;
    int _radius;
    sf::Vector2f _newPoint;
    void transformPoint(double oldX, double oldY);

};


#endif // TRANSFORM_H
