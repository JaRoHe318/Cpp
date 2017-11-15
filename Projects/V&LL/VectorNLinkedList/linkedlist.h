#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

//This is Node===============================================

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(T item):_item(item), _next(NULL){

    }

    template <class U>
    friend ostream& operator <<(ostream& outs,
                                const node<U>& print_me){
        outs<<print_me._item;
        return outs;
    }
};
//#include "node.h"

//These are functions========================================

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
node<T>* _insertAfter(node<T>* &head, node<T>* afterThis,
                      const T &insertThis){
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
node<T>* _insertBefore(node<T>* &head,node<T>* beforeThis,
                       const T &insertThis){

}

template<class T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis){
    node<T>* walker = head;
    node<T>* stalker = NULL;
    if (prevToThis == head){
        return NULL;
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

    if(deleteThis==head){//means you are trying to delete head. ALSO
        head=temp;
    }else{
        prev->_next=temp;
        delete deleteThis;
    }
    return head;
}


template<class T>
node<T>* _copyList(node<T>* head){
    T tempItem;
    node<T>* w = head;
    node<T>* copy = NULL;
    node<T>* copyPtr=NULL;

    if(copy==NULL){
        tempItem=w->_item;
        copy=_insert_head(head,tempItem);
        copyPtr=copy;
        w=w->_next;
    }else{
        while(w!=NULL){
            tempItem = w->_item;
            _insertAfter(copy,w,tempItem);
            w=w->_next;
        }
    }
    return copyPtr;
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
        _deleteNode(head, walker);
        walker = walker->_next;
    }
}



//This is LinkedList=========================================

template <class T>
class List{
public:

    class Iterator{
    public:
        friend class List;

        Iterator();

        Iterator(node<T>* p=NULL):_ptr(p){
        }

        T& operator *(){
            return _ptr->_item;
        }

        T* operator ->(){
            return &(_ptr->_item);
        }

        bool is_null(){
            return _ptr == NULL;
        }

        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            return (left._ptr!=right._ptr);
        }

        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            return (left._ptr==right._ptr);
        }

        Iterator& operator++(){
            _ptr=_ptr->_next;
            return *this;
        }

        friend Iterator operator++(Iterator& it,
                                   int unused){
            List<T>::Iterator hold=it;
            it=it._ptr->_next;
            return hold;
        }

    private:
        node<T>* _ptr;
    };

    List();

    //Big Three
    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List<T> &RHS);

    Iterator InsertHead(T i);           //inset i at the head of list

    Iterator InsertAfter(T i, Iterator iMarker);  //insert i after iMarker

    Iterator InsertRandom(Iterator iMarker);

    Iterator InsertBefore(T i, Iterator iMarker); //insert i before iMarker

    Iterator InsertSorted(T i);         //insert i. Assume sorted list

    Iterator Delete(Iterator iMarker);         //delete node pointed to by iMarker

    void Print() const;

    Iterator Search(const T &key);

    Iterator Next(Iterator iMarker);

    Iterator Prev(Iterator iMarker);    //get the previous node to iMarker

    T& operator[](int index);                   //return the item at index

    Iterator Begin() const;                     //return the head of the list

    Iterator End() const;                       //return the tail of the list

    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l); //insertion operator for list

private:
    node<T>* head;
};


template <class T>
List<T>::List(){
    head = NULL;
}

template <class T>
List<T>::List(const List<T> &copyThis){
    head=_copyList(copyThis.head);
}

template <class T>
List<T>& List<T>::operator =(const List<T>& RHS){
    if(this==&RHS){
        return *this;
    }
    _deleteAll(head);
    head=_copyList(RHS.head);
}

template <class T>
List<T>::~List(){
    _deleteAll(head);
}

template <class T>
typename List<T>::Iterator List<T>::InsertHead(T i){
    return Iterator(_insert_head(head, i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertAfter(T i, Iterator iMarker){
    return Iterator(_insertAfter(head, iMarker._ptr,i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(T i, Iterator iMarker){

}

template <class T>
typename List<T>::Iterator List<T>::Delete(Iterator iMarker){
    _deleteNode(head,iMarker);
}

template<class T>
void List<T>::Print()const {
    _print_list(cout, head);
}

template <class T>
typename List<T>::Iterator List<T>::Next(Iterator iMarker){
    if(iMarker.is_null()){
        return ++iMarker;
    }else{
        return ++iMarker;
    }
}

template <class T>
typename List<T>::Iterator List<T>::Search(const T& item){
    return Iterator(_search_list(head, item));
}

template <class T>
typename List<T>::Iterator List<T>::Prev(Iterator iMarker){
    return Iterator(_previousNode(head,iMarker._ptr));
}

template <class T>
T& List<T>::operator[](int index){
    T inside;
    return inside;
}

template <class T>
typename List<T>::Iterator List<T>::Begin() const{
    return Iterator(head);
}

template <class T>
typename List<T>::Iterator List<T>::End() const{
    return Iterator(_lastNode(head));
}

template<class U>
ostream& operator <<(ostream& outs,const List<U>& l){
    return _print_list(outs, l.head);
}

#endif // LINKEDLIST_H
