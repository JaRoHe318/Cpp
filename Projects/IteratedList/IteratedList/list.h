#ifndef LIST_H
#define LIST_H

#include "functions.h"
#include "node.h"

template <class T>
class List{    
public:

    class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator();                                     //default ctor
        Iterator(node<T>* p);                   //Point Iterator to where p is pointing to
        operator bool();                                //casting operator: true if _ptr not NULL
        //      this turned out to be a pain!


        T& operator *();                        //dereference operator
        T* operator ->();                       //member access operator

        bool is_null();                                 //true if _ptr is NULL

        friend bool operator !=(const Iterator& left,
                                const Iterator& right); //true if left != right

        friend bool operator ==(const Iterator& left,
                                const Iterator& right); //true if left == right

        Iterator& operator++();                         //member operator: ++it; or ++it = new_value

        friend Iterator operator++(Iterator& it,
                                   int unused);         //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };
    List();

    //NotWorkingThree
    ~List();
    //    List(const List<T> &copyThis);
    //    List& operator =(const List<T> &RHS);


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

    Iterator Begin() const;                     //return the head of the list

    Iterator End() const;                       //return the tail of the list

    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l); //insertion operator for list

private:
    node<T>* head;

};

/*
    Iterator Begin() const;                                     //Iterator to the head node
    Iterator End() const;                                       //Iterator to NULL
    Iterator LastNode() const;                                  //Iterator to the last node
private:
    node<ITEM_TYPE>* _head_ptr;
 */


template <class T>
List<T>::List(){
    head = NULL;
}


//template <class T>
//List<T>::List(const List<T> &copyThis){
//    return _copyList(copyThis.Begin());
//}

//template <class T>
//List<T>& List<T>::operator =(const List<T>& RHS){
//    if(this==&RHS){
//        return *this;
//    }
//}

template <class T>
List<T>::~List(){
    _deleteAll(head);
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
typename List<T>::Iterator List<T>::Begin() const{
    return head;
}
template <class T>
typename List<T>::Iterator List<T>::End() const{
    return _lastNode(head);
}

template<class U>
ostream& operator <<(ostream& outs,const List<U>& l){
    return _print_list(outs, l.head);
}

#endif // LIST_H
