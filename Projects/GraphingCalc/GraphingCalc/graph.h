#ifndef GRAPH_H
#define GRAPH_H

#include "consts.h"
#include "point.h"
#include "plotter.h"
#include "jtoken.h"
#include "transform.h"
#include "vector"

class Graph{
public:
    Graph();
    void Update();
    void Pan(char where);
    void Zoom(char how);
    void setDomain();
    void drawGraph(sf::RenderWindow &window);
    void setEquation(JQueue<JToken*> &postFix);


private:
    Plotter p;
    Transform t;
    RPN r;
    JQueue<JToken*> _postFix;
    sf::CircleShape test;
//    JVector<sf::Vector2f> points;
    vector<sf::Vector2f> points;

    void drawAxis(sf::RenderWindow &window);
    void setPoints();
    void setZoomPoints(char how);
    void setDefault();

    sf::RectangleShape yaxis;
    sf::RectangleShape xaxis;
    double xOfY, yOfY, xOfX, yOfX;
    double _domainMin, _domainMax;
    double _domainTotal;
    double _rangeMin, _rangeMax;
    double _incr;

    bool reDraw;
    bool zoomIn;
    bool zoomOut;

};

#endif // GRAPH_H
