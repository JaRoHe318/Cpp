#ifndef PLOTTER_H
#define PLOTTER_H

#include "consts.h"
#include "point.h"
//#include "system.h"
//#include "rpn.h'

class Plotter{
public:
    Plotter();
    Plotter(JQueue<Point> points,double domainMin,
    double domainMax);
    void setDomain(double domainMin, double domainMax);
    void getDomain();

private:
JVector<Point> _points;

double _domainMin;
double _domainMax;
double _incr;
double _domainTotal;

void setPoints(int numPoints);
void matrix();

};

#endif // PLOTTER_H
