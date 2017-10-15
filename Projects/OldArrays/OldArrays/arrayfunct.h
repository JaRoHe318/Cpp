#ifndef ARRAYFUNCT_H
#include <iostream>
using namespace std;

void Print(const int a[], int numUsed);
void ShiftR(int a[],int numUsed,int start);
void ShiftL(int a[],int numUsed,int start);
void Append(int a[], int &numUsed, int num);
void InsertB(int a[],int &numUsed,int InsertMe,int Pos);
void InsertA(int a[],int &numUsed,int InsertMe,int Pos);
void Delete(int a[],int &numUsed,int Pos);
void Search(int a[],int numUsed);
void Sort(int a[],int numUsed);
void Reverse(int a[],int numUsed);



#endif // ARRAYFUNCT_H
