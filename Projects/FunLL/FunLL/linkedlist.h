#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
class LinkedList{

public:

    T _item;
    LinkedList<T>* _next;

    LinkedList(T item= T());

    template <class U>
    friend ostream& operator<<(ostream& outs, const LinkedList<U>& print_me);

};

#endif // LINKEDLIST_H


template<class T>
LinkedList<T>::LinkedList(T item):_item(item), _next(NULL){

}

template <class U>
ostream& operator<<(ostream& outs, const LinkedList<U>& print_me){
    outs<<"["<<print_me._item<<"] ->";
    return outs;
}


