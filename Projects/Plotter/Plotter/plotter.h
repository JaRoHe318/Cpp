#ifndef PLOTTER_H
#define PLOTTER_H

#include "const.h"
#include "point.h"
#include "system.h"

class Plotter{
public:
    Plotter();
    Plotter(JQueue<Point> points,double domainMin,
            double domainMax);

private:
JQueue<Point> _points;
double _domainMin;
double _domainMax;
};

#endif // PLOTTER_H
