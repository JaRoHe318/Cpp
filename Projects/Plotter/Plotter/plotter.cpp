#include "plotter.h"

Plotter::Plotter(){    
    _domainMin=0;
    _domainMax=0;
    //generating test points
    int t=-100;
    for(int i=0;i<201;++i){
        cout<<"\nAdding ( "<<t<<","<<t<<" )\n";

//        _points.Push(Point(t,t));
        ++t;
    }
    //end test points
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

/*
 * | 3 0 | | x | Transformation Matrix
 * | 0 3 | | y |
 *
 *
*/

void Plotter::setPoints(int numPoints){
    _incr=_domainTotal/numPoints;
    double x = _domainMin;
    double y = 0; //Gets value from RPN!

    for(int i=0;i<numPoints;++i){
//        y = RPN(x)
        _points.PushBack(Point());
    }
}

void Plotter::matrix(){

}

//void

