#include "plotter.h"

    _domainMin=0;
    _domainMax=0;
    //generating test points
    int t=-100;
    for(int i=0;i<201;++i){
        cout<<"\nAdding ( "<<t<<","<<t<<" )\n";

        _points.Push(Point(t,t));
        ++t;
    }


    //end test points

}
