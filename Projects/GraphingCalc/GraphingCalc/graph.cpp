#include "graph.h"

Graph::Graph(){
    setDefault();
    yaxis.setSize(sf::Vector2f(LINE_WIDTH,SCREEN_HEIGHT));
    yaxis.setPosition(sf::Vector2f(xOfY, yOfY));
    yaxis.setFillColor(sf::Color(100,100,100));

    xaxis.setSize(sf::Vector2f(SCREEN_WIDTH,LINE_WIDTH));
    xaxis.setPosition(sf::Vector2f(xOfX,yOfX));
//    xaxis.setFillColor(sf::Color(100,100,100));
    xaxis.setFillColor(sf::Color::Red);
}

void Graph::Update(){
    yaxis.setPosition(sf::Vector2f(xOfY, yOfY));
    xaxis.setPosition(sf::Vector2f(xOfX,yOfX));
}

void Graph::Pan(char where){
    switch(where){
    case'l':
        _domainMax=_domainMax-_incr;
        _domainMin=_domainMin-_incr;
        cout<<"Domain {"<<_domainMin<<", "<<_domainMax<<"}\n";
        xOfY = xOfY + _incr;
        p.setDomain(_domainMin,_domainMax);
        break;
    case 'r':
        _domainMax=_domainMax+_incr;
        _domainMin=_domainMin+_incr;
        cout<<"Domain {"<<_domainMin<<", "<<_domainMax<<"}\n";
        xOfY = xOfY - _incr;
        p.setDomain(_domainMin,_domainMax);
        break;
    default:
        break;
    }
}

void Graph::Zoom(char how){
    switch(how){
    case 'i':
//        plot.setDomain();
        break;
    case 'o':
//        plot.setDomain();
        break;
    default:
        break;

    }
}

void Graph::setEquation(JQueue<JToken*> &postFix){
    //gives plotter equation
}

void Graph::setDomain(double domainMin, double domainMax){
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
    _incr=_domainTotal/NUM_POINTS;
    p.setDomain(domainMin,domainMax);
}

void Graph::drawGraph(sf::RenderWindow &window){
       window.draw(xaxis);
       window.draw(yaxis);
}

void Graph::setDefault(){
    //origin defaults
    //Y-axis
    _incr=0;
    _domainMax=10;
    _domainMin=-10;
    _domainTotal=_domainMax-_domainMin;
    _incr=(_domainTotal/NUM_POINTS)*1000;

    xOfY = (SCREEN_WIDTH/2)-(LINE_WIDTH/2);
    yOfY = 0;
    xOfX = 0;
    yOfX = (SCREEN_HEIGHT/2)-(LINE_WIDTH/2);
}
