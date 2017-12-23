#ifndef PLOTTER_H
#define PLOTTER_H

#include "const.h"
#include "point.h"
<<<<<<< HEAD
#include "system.h"
=======
//#include "system.h"
//#include "rpn.h'
>>>>>>> bd13df3c52a4c9124c8eaf6c37838bb2631f3b02

class Plotter{
public:
    Plotter();
    Plotter(JQueue<Point> points,double domainMin,
    double domainMax);
    void setDomain(double domainMin, double domainMax);
    void getDomain();

private:
<<<<<<< HEAD
JQueue<Point> _points;
double _domainMin;
double _domainMax;
=======
JVector<Point> _points;

double _domainMin;
double _domainMax;
double _incr;
double _domainTotal;

void setPoints(int numPoints);
void matrix();

>>>>>>> bd13df3c52a4c9124c8eaf6c37838bb2631f3b02
};

#endif // PLOTTER_H
