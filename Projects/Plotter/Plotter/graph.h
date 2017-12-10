#ifndef GRAPH_H
#define GRAPH_H

#include "const.h"
#include "point.h"

class Graph{
public:
    Graph();
    Graph(sf::Window &window);
    void Update();
private:
    JVector<Point> points;
    bool reCalculate;

};

#endif // GRAPH_H
