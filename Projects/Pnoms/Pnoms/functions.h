#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;
#include <iostream>
#include <cassert>
#include <cstring>

typedef double T;

class functions{

public:
    functions();
    T *allocate(int size);
    T* copy_array(T* src, int size);
    T* resize(T* src, int oldSize, int newSize);
    T* delete_array(T* &a);
};

#endif // FUNCTIONS_H
