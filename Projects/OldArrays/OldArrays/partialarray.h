#ifndef PARTIALARRAY_H
#define PARTIALARRAY_H
#include <iostream>
using namespace std;
#include "arrayfunct.h"

const int MAX = 100;

class PartialArray{

private:
    //variables
    int array[MAX];
    int numUsed;
    int num;
public:
    PartialArray();
    PartialArray(const int a[], int &size);
    void Print()const ;
    int At(int i)const;
    int ShiftR(int start);
    int ShiftL(int start);
    int Append(int num);
    int InsertB(int InsertMe,int Pos);
    int InsertA(int InsertMe,int Pos);
    int Delete(int Pos);
    int Search();
    void Sort();
    void Reverse();
    void DeleteRepeats();
    int NumUsing() const;
    int& operator[](int i); //Apparently this CANNOT be a friend.....
}; //class

#endif // PARTIALARRAY_H
