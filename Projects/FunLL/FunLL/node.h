#ifndef NODE_H
#define NODE_H

using namespace std;
#include <iostream>

template<class T>
struct Node{

public:

    T _item;
    Node<T>* _next;
    Node();
    Node(const T &item= T());

    template <class U>//if you have an op in a Template that is being defined outside of this?
    friend ostream& operator<<(ostream& outs, const Node<U>& print_me);

};


template<class T>
Node<T>::Node(){

}

template<class T>
Node<T>::Node(const T &item):_item(item), _next(NULL){

}

template <class U>
ostream& operator<<(ostream& outs, const Node<U>& print_me){
    outs<<"["<<print_me._item<<"] ->";
    return outs;
}

#endif // Node_H
