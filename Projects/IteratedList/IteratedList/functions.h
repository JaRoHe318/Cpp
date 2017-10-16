#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;
#include <iostream>
#include "node.h"

template<class U>
ostream& _print_list(ostream &outs, node<U>* head_ptr){
    node<U>* walker = head_ptr;
    outs<<"H-> ";
    while (walker!=NULL){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<" ->|||"<<endl;
    return outs;
}

template <class T>
node<T>* _search_list(node<T>* &head_ptr, const T& item){
    node<T>* w;
    for (w = head_ptr; w!=NULL;w=w->_next){
        if (w->_item == item)
            return w;
    }
    return NULL;
}

template <class T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item){

    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;
    return head_ptr;
}

template <class T>
node<T>* _insertAfter(node<T>* &head, node<T>* afterThis ,const T &insertThis){
    if(afterThis==NULL){
        return _insert_head(head,insertThis);
    }else{
        node<T>* temp = new node<T>(insertThis);
        temp->_next=afterThis->_next;
        afterThis->_next = temp;
        return temp;
    }
}

template<class T>
node<T>* _insertRand(node<T>* &head,node<T>* afterThis){
    int ran=rand() % 100 + 1;
    return _insertAfter(head, afterThis, ran);
}

template<class T>
node<T>* _insertBefore(node<T>* &head,node<T>* beforeThis ,const T &insertThis){

}
template<class T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis){
    node<int>* walker = head;
    node<int>* stalker = NULL;

    if (prevToThis == head){
        return head;
    }
    while (walker!=NULL){
        stalker=walker;
        walker = walker->_next;
        if(walker==prevToThis){
            return stalker;
        }
    }
}
template<class T>
node<T>* _deleteNode(node<T>* &head, node<T>* deleteThis){
    node<T>* temp = deleteThis->_next;
    node<T>* prev = _previousNode(head,deleteThis); //prev should return null if deleteThis is pointing to head
    //
    if (prev == NULL){//means you are trying to delete head
        head = temp;
    }
    if(deleteThis==head){//means you are trying to delete head. ALSO
        head=temp;
    }else{
        prev->_next=temp;
    }
    delete deleteThis;
    return head;
}

template<class T>
node<T>* _copyList(node<T>* head){

}

template<class T>
node<T>* _lastNode(node<T>* head){
    node<int>* walker = head;

    while (walker!=NULL){
        if(walker->_next==NULL){
            return walker;
        }
        walker = walker->_next;
    }
    return head;
}

template <class T>
void _deleteAll(node<T>* &head){
    node<int>* walker = head;

    while (walker!=NULL){
        cout<<"."<<endl;
        _deleteNode(head, walker);
        walker = walker->_next;
    }
}


#endif // FUNCTIONS_H
