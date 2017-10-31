#ifndef JVECTOR_H
#define JVECTOR_H

#include "vfunctions.h"

template<class T>
class JVector{
public:

    class Iterator{
    public:
        //give access to list to access _ptr
        friend class JVector;

        //default ctor
        Iterator();

        //Point Iterator to where p is pointing to
        Iterator(JVector<T>* p=NULL):_ptr(p){
        }

        //dereference operator
        T& operator *(){
            return *_ptr;
        }


        //member access operator
        T* operator ->(){
            return &(*_ptr);
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
            //            _ptr=_ptr->_next;

            ++_ptr;
            return *this;
        }

        //friend operator: it++
        friend Iterator operator++(Iterator& it, int unused){
            JVector<T>::Iterator hold=it;
            ++it;
            return hold;
            //            it=it._ptr->_next;
            //            return hold;
        }

    private:
        //pointer being encapsulated
        JVector<T>* _ptr;
    };

    JVector();
    JVector(int size, T fullOfThis);


    //Big Twee
    ~JVector();
    JVector(const JVector<T> &copyThis);
    JVector& operator =(const JVector<T> &RHS);

    T& operator[](int index)const;

    Iterator Begin() const;

    Iterator End() const;

    JVector PushBack(T pushThis);

    template <class U>
    friend ostream& operator <<(ostream& outs, const JVector<U>& j); //insertion operator for list


private:
    T* v;
    int capacity;

};

template<class T>
JVector<T>::JVector():capacity(100){
    v = new T[capacity];
}

template<class T>
JVector<T>::JVector(int size, T fullOfThis){
    capacity=size;
    v = new T[capacity];
    Fill(v,fullOfThis,capacity);
}

template<class T>
JVector<T>::~JVector(){
    delete []v;
}

template<class T>
JVector<T>::JVector(const JVector<T> &copyThis){
    v=_copyArray(copyThis,copyThis.capacity);
}

template<class T>
JVector<T>& JVector<T>::operator =(const JVector<T> &RHS){
    if(this==&RHS){
        return *this;
    }
    delete []v;
    v=_copyArray(RHS.v,RHS.capacity);
}


template<class T>
typename JVector<T>::Iterator JVector<T>::Begin()const{
    return Iterator(v);
}

template<class T>
typename JVector<T>::Iterator JVector<T>::End()const{
    return Iterator(v+capacity);
}

template<class T>
JVector PushBack(T pushThis){

}

template<class T>
T& JVector<T>::operator[](int index)const{
    return v[index];
}

template<class U>
ostream& operator <<(ostream& outs,const JVector<U>& j){
    for(int i=0;i<j.capacity;++i){
        outs<<j[i]<<" ";
    }
    return outs;
}

#endif // JVECTOR_H
