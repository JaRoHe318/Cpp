#include "graph.h"

Graph::Graph(){
    setDefault();
    yaxis.setSize(sf::Vector2f(LINE_WIDTH,SCREEN_HEIGHT));
    yaxis.setPosition(sf::Vector2f(xOfY, yOfY));
    yaxis.setFillColor(sf::Color(100,100,100));

    xaxis.setSize(sf::Vector2f(SCREEN_WIDTH,LINE_WIDTH));
    xaxis.setPosition(sf::Vector2f(xOfX,yOfX));
    xaxis.setFillColor(sf::Color::Red);

    test= sf::CircleShape(1);
    test.setFillColor(sf::Color::Cyan);
}

void Graph::Update(){
    if(_domainMin<=0){
        xOfY = ((-_domainMin)/(_domainTotal)*SCREEN_WIDTH)-(LINE_WIDTH/2);
    }else{
        xOfY = -1;
    }

    if(reDraw){
        setPoints();
        reDraw=false;
    }

    if(zoomIn){
        setZoomPoints('i');
        zoomIn=false;
    }
    if(zoomOut){
        setZoomPoints('o');
        zoomOut=false;
    }

    points.clear();


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
        points.clear();
        reDraw=true;
        break;
    case 'r':
        _domainMax=_domainMax+_incr;
        _domainMin=_domainMin+_incr;
        cout<<"Domain {"<<_domainMin<<", "<<_domainMax<<"}\n";
        xOfY = xOfY - _incr;
        points.clear();
        reDraw=true;
        break;
    default:
        break;
    }

}

void Graph::Zoom(char how){
    switch(how){
    case 'i':
        points.clear();
        setZoomPoints('i');
        zoomIn=true;
        break;
    case 'o':
        points.clear();
        setZoomPoints('o');
        zoomOut=true;
        break;
    default:
        break;

    }
}

void Graph::setEquation(JQueue<JToken*> &postFix){
    p.setEquation(postFix);
    _postFix=postFix;
    setPoints();
    reDraw=true;
}

void Graph::setDomain(){
    cout<<"\nSet Min: ";
    cin>>_domainMin;
    cout<<"\nSet Max: ";
    cin>>_domainMax;
    _domainTotal=_domainMax-_domainMin;
    _incr=(_domainTotal/NUM_POINTS)*1000;
    points.clear();
    reDraw=true;
}

void Graph::drawGraph(sf::RenderWindow &window){
    window.draw(xaxis);
    window.draw(yaxis);
    for(int i=0;i<NUM_POINTS;++i){
        test.setPosition(sf::Vector2f(points[i].x,points[i].y));
        //        test.setPosition(points[i]);
        window.draw(test);
    }
    points.clear();

}

void Graph::setDefault(){
    //origin defaults
    //Y-axis
    _domainMax=100;
    _domainMin=-100;
    _domainTotal=_domainMax-_domainMin;
    _incr=(_domainTotal/NUM_POINTS)*1000;
    reDraw = false;
    zoomIn = false;
    zoomOut = false;

    xOfY = (SCREEN_WIDTH/2)-(LINE_WIDTH/2);
    yOfY = 0;
    xOfX = 0;
    yOfX = (SCREEN_HEIGHT/2)-(LINE_WIDTH/2);
}

void Graph::setPoints(){
    double x = _domainMin;
    double y = 0; //Gets value from RPN!
    sf::Vector2f newPt;
    _domainTotal=_domainMax-_domainMin;
    double incr=(_domainTotal/NUM_POINTS);
    for(int i=0;i<NUM_POINTS;++i){
        r.getY(x,_postFix);
        y = r.getAnswer();
        t.setDomain(_domainMin,_domainMax);
        t.setPoint(x,y);
        newPt=t.getNewPoint();
        points.push_back(newPt);
        x=x+incr;
    }
}

void Graph::setZoomPoints(char how){
    double x = _domainMin;
    double y = 0; //Gets value from RPN!
    double zoomFactor=1;
    if(how=='i'){
        zoomFactor=2;

    }else{
        zoomFactor=.75;
    }

    sf::Vector2f newPt;
//    _domainTotal=_domainMax-_domainMin;
    double incr=(_domainTotal/NUM_POINTS);
    for(int i=0;i<NUM_POINTS;++i){
        r.getY(x,_postFix);
        y = r.getAnswer();
        t.setDomain(_domainMin,_domainMax);
        t.setPoint(zoomFactor*x,zoomFactor*y);
        newPt=t.getNewPoint();
        points.push_back(newPt);
        x=x+incr;
    }

    _domainMax=_domainMax/zoomFactor;
    _domainMin=_domainMin/zoomFactor;
    _domainTotal=_domainMax-_domainMin;
    _incr=(_domainTotal/NUM_POINTS)*1000;
}

