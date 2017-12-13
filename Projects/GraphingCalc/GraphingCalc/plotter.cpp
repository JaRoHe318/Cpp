#include "plotter.h"

Plotter::Plotter(){

}
Plotter::Plotter(JQueue<Point> points, double domainMin, double domainMax){

}

void Plotter::setDomain(double domainMin, double domainMax){
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
}

void Plotter::getDomain(){
    cout<<"\nFrom ["<<_domainMin<<" to "<<_domainMax<<"]\n";
}



void Plotter::setPoints(int numPoints){
    _incr=_domainTotal/numPoints;
    double x = _domainMin;
    double y = 0; //Gets value from RPN!

    for(int i=0;i<numPoints;++i){
//        y = RPN(x)
        _points.PushBack(Point());
    }
}
