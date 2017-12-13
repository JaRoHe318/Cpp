#ifndef GRAPH_H
#define GRAPH_H

#include "consts.h"
#include "point.h"
#include "plotter.h"
#include "jtoken.h"

class Graph{
public:
    Graph();
    void Update();
    void Pan(char where);
    void Zoom(char how);
//    void setEquation(string equation);
    void setDomain(double domainMin, double domainMax);
    void drawGraph(sf::RenderWindow &window);
    void setEquation(JQueue<JToken*> &postFix);
private:
    Plotter p;
    JVector<Point> points;
    void setDefault();

    sf::RectangleShape yaxis;
    sf::RectangleShape xaxis;
    double xOfY, yOfY, xOfX, yOfX;
    double _domainMin, _domainMax;
    double _domainTotal;
    double _rangeMin, _rangeMax;
    double _incr;
    void drawAxis(sf::RenderWindow &window);
};

#endif // GRAPH_H
