#ifndef LIST_H
#define LIST_H


#include "functions.h"
#include "node.h"

//start
template <class T>
class List{

public:
    List();

            ~List();
    //        List(const List<T> &copyThis);
            List& operator =(const List<T> &RHS);

    node<T>* InsertHead(T i);           //inset i at the head of list

    node<T>* InsertAfter(T i, node<T>* iMarker);  //insert i after iMarker

    node<T>* InsertRandom(node<T>* iMarker);

    node<T>* InsertBefore(T i, node<T>* iMarker); //insert i before iMarker


    node<T>* InsertSorted(T i);         //insert i. Assume sorted list



    node<T>* Delete(node<T>* iMarker);         //delete node pointed to by iMarker



    void Print() const;

    node<T>* Search(const T &key);


    node<T>* Next(node<T>* iMarker);

    node<T>* Prev(node<T>* iMarker);    //get the previous node to iMarker


    T& operator[](int index);                   //return the item at index

    node<T>* Begin() const;                     //return the head of the list

    node<T>* End() const;                       //return the tail of the list

    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l); //insertion operator for list

private:
    node<T>* head;

};
//end

template <class T>
List<T>::List(){
    head = NULL;
}/*
template <class T>
List<T>::List(const List<T> &copyThis){

}

template <class T>
List<T>& List<T>::operator =(const List<T>& RHS){
    if(this==&RHS){
        return *this;
    }


}*/
template <class T>
List<T>::~List(){
//    _deleteAll(head);
}
template <class T>
node<T>* List<T>::InsertHead(T i){
    return _insert_head(head, i);
}

template <class T>
node<T>* List<T>::InsertAfter(T i, node<T>* iMarker){
    return _insertAfter(head, iMarker,i);
}

template <class T>
node<T>* List<T>::InsertRandom(node<T>* iMarker){
    return _insertRand(head,iMarker);
}

template <class T>
node<T>* List<T>::InsertBefore(T i, node<T>* iMarker){

}

template <class T>
node<T>* List<T>::InsertSorted(T i){

}

template <class T>
node<T>* List<T>::Delete(node<T>* iMarker){
    _deleteNode(head,iMarker);
//    _deleteAll(head);
}

template<class T>
void List<T>::Print()const {
    _print_list(cout, head);
}

template <class T>
node<T>* List<T>::Search(const T& item){
    return _search_list(head, item);
}

template <class T>
node<T>* List<T>::Prev(node<T>* iMarker){
    return _previousNode(head,iMarker);
}

template <class T>
node<T>* List<T>::Next(node<T>* iMarker){
    if(iMarker->_next==NULL){
        return iMarker;
    }else{
        iMarker=iMarker->_next;
        return iMarker;
    }
}

template <class T>
T& List<T>::operator[](int index){
    T inside;
    return inside;
}

template <class T>
node<T>* List<T>::Begin() const{
    return head;
}
template <class T>
node<T>* List<T>::End() const{
   return _lastNode(head);
}


template<class U>
ostream& operator <<(ostream& outs,const List<U>& l){
    return _print_list(outs, l.head);
}

#endif // LIST_H
