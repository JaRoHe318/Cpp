#ifndef LIST_H
#define LIST_H

#include "functions.h"
#include "node.h"

template <class T>
class List{
public:

    class Iterator{
    public:
        //give access to list to access _ptr
        friend class List;

        //default ctor
        Iterator();

        //Point Iterator to where p is pointing to
        Iterator(node<T>* p=NULL):_ptr(p){

        }

        //dereference operator
        T& operator *(){
            return _ptr->_item;
        }


        //member access operator
        T* operator ->(){
            return &(_ptr->_item);
        }

        //true if _ptr is NULL
        bool is_null(){
            return _ptr == NULL;
        }

        //true if left != right
        friend bool operator !=(const Iterator& left,
                                const Iterator& right){
            return (left._ptr!=right._ptr);
        }

        //true if left == right
        friend bool operator ==(const Iterator& left,
                                const Iterator& right){
            return (left._ptr==right._ptr);
        }

        //member operator: ++it; or ++it = new_value
        Iterator& operator++(){
            _ptr=_ptr->_next;
            //            return _ptr->_item;
            return *this;
        }

        //friend operator: it++
        friend Iterator operator++(Iterator& it,
                                   int unused){
            List<T>::Iterator hold=it;
//            hold = it;

            it=it._ptr->_next;
            return hold;
        }

    private:
        //pointer being encapsulated
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
    bool _order;
    bool _unique;
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
typename List<T>::Iterator List<T>::InsertRandom(Iterator iMarker){
    return Iterator(_insertRand(head,iMarker._ptr,_order));
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(T i, Iterator iMarker){

}

template <class T>
typename List<T>::Iterator List<T>::InsertSorted(T i){
    return Iterator(InsertSorted(head,i,_order));
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

#endif // LIST_H
