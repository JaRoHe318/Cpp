#ifndef LIST_H
#define LIST_H

#include "jvector.h"

template <class T>
class List{
public:

    class Iterator{
    public:
        friend class List;

        //        Iterator(){

        //        }

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
            //                        ++pos;
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
        typename JVector<T>::Iterator _ptr;
        int pos; //how far am I from begin

    };//Iterator

    List();

    T& operator[](int index);

    void Insert(T insertMe);

    Iterator Begin() const;

    Iterator End() const;


private:
    JVector<T> _ptr;

};//list


template <class T>
List<T>::List(){
}

template<class T>
T& List<T>::operator[](int index){
    return _ptr[index];
}

//void List<T>::Insert(T insertMe){
//    _ptr
//}

template <class T>
typename List<T>::Iterator List<T>::Begin() const{
    typename JVector<T>::Iterator it;
//    Iterator(it = _ptr->Begin());
      return Iterator(it);
}

template <class T>
typename List<T>::Iterator List<T>::End() const{
    typename JVector<T>::Iterator it;
    Iterator(it = _ptr->End());
}


#endif // LIST_H
