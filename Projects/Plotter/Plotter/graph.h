#ifndef GRAPH_H
#define GRAPH_H

#include "const.h"
#include "point.h"
#include "plotter.h"

class Graph{
public:
    Graph();
    void Update();
    void Pan(char where);
    void Zoom(char how);
    void setEquation(string equation);
    void setDomain(double domainMin, double domainMax);
    void drawGraph(sf::RenderWindow &window);
private:
    sf::RectangleShape yaxis;
    sf::RectangleShape xaxis;
    Plotter p;
    JVector<Point> points;
    bool reCalculate;
    void drawAxis(sf::RenderWindow &window);
    void setDefault();
    double xOfY, yOfY, xOfX, yOfX;

    double _numPoints;
    double _domainMin, _domainMax;
    double _rangeMin, _rangeMax;
    double _incr;
    double _domainTotal;
};

#endif // GRAPH_H
