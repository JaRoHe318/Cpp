#ifndef ARRAYNAV_H
#define ARRAYNAV_H
#include <iostream>
#include "partialarray.h"

using namespace std;
class ArrayNav{
private:
    int cPos;
    PartialArray arr;
public:
    ArrayNav();
    ArrayNav(const int a[], int &size);
    int Left();
    int Right();
    int Insert(int InsertMe);
    int Append(int AppendMe);
    int Delete();
    int Search(int key);
    //  friend const ArrayNav&
    friend ostream& operator <<(ostream& out, const ArrayNav& an);
};

#endif // ARRAYNAV_H
