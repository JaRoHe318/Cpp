#include "functions.h"

functions::functions(){

}
//Lowest Lvl Functions
T* functions::allocate(int size){
    T* al;
    T* temp;
    al = new T[size];
    temp=al;
    for(int i = 0;i<size;i++){
        *temp=0;
        temp++;
    }
    return al;//returns address of newly created array
}
T* functions::copy_array(T* src, int size){
    T* copy = new T[size];
    T* p;
    p=copy;
    for(int i=0; i<size; i++){
        *p = *src;
        p++;
        src++;
    }
    return copy;//returns address of new array copy
}
T* functions::resize(T* src,int oldSize, int newSize){//takes an array, puts in longer array, deletes old array.
    T* temp;
    T* w;
    w=src;
    temp=allocate(newSize);//allocates new array of 0s
    for(int i = 0;i<oldSize;i++){
        *temp=*w;
        temp++;
        w++;
    }
    delete [] src; // may not need ?
    return temp; //returns location of new array
}
T *functions::delete_array(T* &a){
    delete [] a;
}




