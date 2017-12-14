#ifndef PLOTTER_H
#define PLOTTER_H

#include "consts.h"
#include "point.h"
#include "rpn.h"
#include "jtoken.h"
#include "transform.h"

class Plotter{
public:
    Plotter();
    Plotter(vector<sf::Vector2f> &points,double domainMin,
    double domainMax);
    void setDomain(vector<sf::Vector2f> &points, double domainMin, double domainMax);
    void setDomain(double domainMin, double domainMax);

    void getDomain();
    void setEquation(JQueue<JToken*> &postFix);
    void setPoints();

private:
//JVector<Point> _points;
vector<sf::Vector2f> _points;
Transform t;
JQueue<JToken*> _postFix;
RPN r;
double _domainMin;
double _domainMax;
double _incr;
double _domainTotal;

void matrix();

};

#endif // PLOTTER_H
