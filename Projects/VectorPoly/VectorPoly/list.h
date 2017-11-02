#ifndef LIST_H
#define LIST_H

#include "jvector.h"

template <class T>
class List{
public:
    class Iterator{
    public:
        friend class List;

        Iterator();

        Iterator(typename JVector<T>::Iterator it=NULL):_ptr(it){
            pos=0;
        }

        T& operator *(){
            return *_ptr;
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
            ++_ptr;
            ++pos;
            return *this;
        }

        friend Iterator operator++(Iterator& it, int unused){
            List<T>::Iterator hold=it;
            ++it;
            //            ++pos;
            return hold;
        }

        Iterator& operator--(){
            --_ptr;
            --pos;
            return *this;
        }

        friend Iterator operator--(Iterator& it, int unused){
            List<T>::Iterator hold=it;
            //            --pos;
            --it;
            return hold;
        }

    private:
//        JVector<T>* _ptr;
        JVector<T>::Iterator* _ptr;
        int pos;//how far am I from begin

    };//Iterator

    List();

    Iterator Begin() const;

    Iterator End() const;


private:
    JVector<T>::Iterator* _ptr;
//    JVector<T>* _ptr;
};//list


template <class T>
List<T>::List(){
    _ptr = NULL;
}

Iterator List<T>::Begin() const{
    Iterator(JVector<T>::Iterator it = _ptr->Begin());
}

Iterator List<T>::End() const{
    Iterator(JVector<T>::Iterator it = _ptr->End());
}


#endif // LIST_H
