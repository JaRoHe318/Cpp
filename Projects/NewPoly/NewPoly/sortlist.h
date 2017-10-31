#ifndef SORTLIST_H
#define SORTLIST_H

#include "listfunctions.h"
#include "node.h"

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

        //friend operator: it++
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

    Iterator InsertRandom(Iterator iMarker);

    Iterator InsertSorted(T i);

    Iterator Delete(Iterator iMarker);

    void Print() const;

    Iterator Search(const T &key);

    Iterator Next(Iterator iMarker);

    Iterator Prev(Iterator iMarker);
    T& operator[](int index);

    Iterator Begin() const;

    Iterator End() const;

    template <class U>
    friend ostream& operator <<(ostream& outs, const List<U>& l); //insertion operator for list

private:
    node<T>* head;
    bool _order=false;
    bool _unique=true;
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
typename List<T>::Iterator List<T>::InsertRandom(Iterator iMarker){
    return Iterator(_insertRand(head,iMarker._ptr));
}


template <class T>
typename List<T>::Iterator List<T>::InsertSorted(T i){
    return Iterator(_InsertSorted(head,i,_order));
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
    List<T>::Iterator it = head;
    for(int i = 0;i<=index;++i){
    ++it;
    }
    return *it;
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

#endif // SORTLIST_H
