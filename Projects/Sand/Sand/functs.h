#ifndef FUNCTS_H
#define FUNCTS_H

template <class T>
void destroy_array(T* &src){
    if (src){
        delete[] src;
    }
    src = NULL;
}

template <class T>
T* copy_array(T* src, int size){
    T* copy = new T[size];
    for (int i=0; i<size; i++){
        copy[i] = src[i];
    }
    return copy;
}


#endif // FUNCTS_H
