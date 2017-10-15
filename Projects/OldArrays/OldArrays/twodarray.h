#ifndef TWODARRAY_H
#define TWODARRAY_H
#include "partialarray.h"

const int COL =100;
const int ROW=100;

class TwoDArray{

private:
    int c[COL];
    PartialArray PA;
    int TwoD[ROW][COL];
public:
    TwoDArray();
    TwoDArray(int td[][COL], int row, int col);
    int Append(int AppendMe,int row);
    int Insert(int InsertMe,int row,int col);
    int Delete(int row,int col);

    void Print(int row,int col);
    //    friend ostream& operator <<(ostream& out, const TwoDArray& td);

};

#endif // TWODARRAY_H
