#include "arrayfunct.h"

void Print(const int a[], int numUsed){
    cout<<"\n\nprnt arryfunct\n\n";
    for(int i = 0;i<numUsed;i++){
        cout<<" "<<a[i];
    } //for
} //void

void ShiftR(int a[], int numUsed, int start){
    int i = start;
    int j = start + 1;
    int temp;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

void ShiftL(int a[], int numUsed, int start){
    int i = start;
    int j = start - 1;
    int temp;
    temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

void Append(int a[], int &numUsed, int num){
    int i = numUsed;
    a[i]=num;
    numUsed ++;
} //void

void InsertB(int a[], int &numUsed, int InsertMe, int Pos){
    int numBef = numUsed - 1;
    int i = numBef-1;
    int j = numBef;

    a[numUsed] = a[numBef];
    while(j != Pos){
        a[j]=a[i];
        j--;
        i--;
    }
    a[Pos] = InsertMe;
    numUsed++;
}

void InsertA(int a[], int &numUsed, int InsertMe, int Pos){
    int numBef = numUsed - 1;
    int i = numBef;
    int j = numUsed;
    a[numUsed] = a[numBef];
    while(i != Pos){
        a[j]=a[i];
        j--;
        i--;
    }//while
    a[Pos+1] = InsertMe;
    numUsed++;
}//void

void Delete(int a[], int &numUsed, int Pos){
    int i = Pos;
    while(i<numUsed){
        a[i]=a[i+1];
        i++;
    }
    numUsed--;
}//void
