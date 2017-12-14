#include "plotter.h"

Plotter::Plotter(){
}
Plotter::Plotter(vector<sf::Vector2f> &points, double domainMin, double domainMax){
    _points=points;
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
}

void Plotter::setDomain(double domainMin, double domainMax){
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
}

void Plotter::setDomain(vector<sf::Vector2f> &points,double domainMin,
                        double domainMax){
    _points=points;
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
}

void Plotter::getDomain(){
    cout<<"\nFrom ["<<_domainMin<<" to "<<_domainMax<<"]\n";
}

void Plotter::setPoints(){
    double x = _domainMin;
    double newX=0;
    double newY=0;
    sf::Vector2f newPt;
    double y = 0; //Gets value from RPN!
    _incr=_domainTotal/NUM_POINTS;
    for(int i=0;i<NUM_POINTS;++i){
        r.getY(x,_postFix);
        y= r.getAnswer();
        t.setDomain(_domainMin,_domainMax);
        t.setPoint(x,y);
        newPt=t.getNewPoint();
        _points.push_back(newPt);
//        cout<<"RPNx:"<<x<<"\nY:"<<y<<endl;
        x=x+_incr;
    }
}

void Plotter::setEquation(JQueue<JToken *> &postFix){
    _postFix=postFix;
}


