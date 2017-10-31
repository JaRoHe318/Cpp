#ifndef VFUNCTIONS_H
#define VFUNCTIONS_H

using namespace std;
#include <iostream>

template <class T>
T* _copyArray(T* copyThis,int size){
    T* copy=new T[size];
    for(int i=0;i<size;i++){
        copy[i]=copyThis[i];
    }
    return copy;//returns pointer to copied array
}

template <class T>
void Fill(T* &fillThis,T filler, int size){
    for(int i=0;i<size;++i){
        fillThis[i]=filler;
    }
}



#endif // VFUNCTIONS_H
