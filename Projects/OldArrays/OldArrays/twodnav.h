#ifndef TWODNAV_H
#define TWODNAV_H
#include "twodarray.h"

const int COLSS =100;

class TwoDNav{

private:
    int rowC;
    int colC;
    TwoDArray TwoD;
    PartialArray arr;



public:
    TwoDNav();
    TwoDNav(int t[][COLSS],int row,int col);

    int Left();
    int Right();
    int Up();
    int Dow();
    int Insert(int InsertMe);
    int Append(int AppendMe);
    int Delete();

    void Print();




};

#endif // TWODNAV_H
