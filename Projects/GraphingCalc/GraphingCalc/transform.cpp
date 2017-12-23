#include "transform.h"

Transform::Transform(){
    _domainMax=100;
    _domainMin=-100;
    _rangeMin=-60;
    _rangeMax = 60;
    _radius=20;
    _domainTotal=_domainMax-_domainMin;
    _rangeTotal=_rangeMax-_rangeMin;
}

Transform::Transform(double domainMin, double domainMax,
                     double rangeMin, double rangeMax){
    _domainMax=domainMax;
    _domainMin=domainMin;
    _rangeMax=rangeMax;
    _rangeMin=rangeMin;
    _domainTotal=_domainMax-_domainMin;
}

void Transform::setDomain(double domainMin, double domainMax){
    _domainMax=domainMax;
    _domainMin=domainMin;
    _domainTotal=_domainMax-_domainMin;
}

void Transform::setPoint(double oldX,double oldY){
    transformPoint(oldX,oldY);
}

void Transform::setPoint(sf::Vector2f oldPoint){

}

sf::Vector2f Transform::getNewPoint(){
    return _newPoint;
}

void Transform::transformPoint(double oldX, double oldY){
//    cout<<"oldX:"<<oldX<<"\nOldY:"<<oldY<<endl;
    _newX = ((oldX-_domainMin)/(_domainTotal)*SCREEN_WIDTH);
    _newY = ((-oldY - _rangeMin)/(_rangeTotal)*SCREEN_HEIGHT);
//    _newY = ((_rangeMin-oldY)/(_rangeTotal)*SCREEN_HEIGHT);
//    cout<<"\nNEWX!:"<<_newX<<endl<<"\nNEWY: "<<_newY;

    _newPoint = sf::Vector2f(_newX,_newY);

}


void Transform::zoomPoint(double oldX,double oldY,char how) {
    double newX=0;
    double newY=0;
    double zoomFactor=1.5;
    switch(how){
    case 'i':
        newX=oldX*zoomFactor;
        newY=oldY*zoomFactor;
        break;
    case 'o':
        newX=oldX/zoomFactor;
        newY=oldY/zoomFactor;
        break;
    default:
        break;
    }

}
