#ifndef JVECTOR_H
#define JVECTOR_H

#include "vfunctions.h"

template<class T>
class JVector{
public:

    class Iterator{
    public:
        friend class JVector;

//        Iterator(){

//        }

        Iterator(T* p=NULL):_ptr(p){
        }

        T& operator *(){
            return *_ptr;
        }

        T* operator ->(){
            return &(*_ptr);
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
            return *this;
        }

        friend Iterator operator++(Iterator& it, int unused){
            JVector<T>::Iterator hold=it;
            ++it;
            return hold;
        }

        Iterator& operator--(){
            --_ptr;
            return *this;
        }

        friend Iterator operator--(Iterator& it, int unused){
            JVector<T>::Iterator hold=it;
            --it;
            return hold;
        }

    private:
        T* _ptr;
    };

    JVector( );
    JVector(int size, T fullOfThis);

    //Big Twee
    ~JVector();
    JVector(const JVector<T> &copyThis);
    JVector& operator =(const JVector<T> &RHS);

    T& operator[](int index);

    Iterator Begin() const;

    Iterator End() const;

    void PushBack(T pushThis);

    void PopBack();

    template <class U>
    friend ostream& operator <<(ostream& outs, const JVector<U>& j); //insertion operator for list
private:
    T* v;
    int capacity;
    int howMany;
};

template<class T>
JVector<T>::JVector(){
    capacity=200;//was200!
    howMany=0;
    v = new T[capacity];
}

template<class T>
JVector<T>::JVector(int size, T fullOfThis){
    capacity=2*size;
    howMany=size;
    v = new T[capacity];
    Fill(v,fullOfThis,size);
}

template<class T>
JVector<T>::~JVector(){
    delete []v;
}

template<class T>
JVector<T>::JVector(const JVector<T> &copyThis){
    v=_makeCopy(copyThis,copyThis.capacity);
}

template<class T>
JVector<T>& JVector<T>::operator =(const JVector<T> &RHS){
    if(this==&RHS){
        return *this;
    }
    delete []v;
//    this(RHS);
    v=_makeCopy(RHS.v,RHS.capacity);
    howMany=RHS.howMany;
}


template<class T>
typename JVector<T>::Iterator JVector<T>::Begin()const{
    return Iterator(v);
}

template<class T>
typename JVector<T>::Iterator JVector<T>::End()const{
    return Iterator(v+howMany);
}

template<class T>
void JVector<T>::PushBack(T pushThis){
    if(howMany==capacity){
        capacity=2*howMany;
        T* temp = new T[capacity];
        _copyArray(v,temp,howMany);
        delete []v;
        v=temp;
    }
    v[howMany]=pushThis;
    ++howMany;
}


template<class T>
void JVector<T>::PopBack(){
    --howMany;
}

template<class T>
T& JVector<T>::operator[](int index){
    if(index>howMany){
        howMany=index+1;
    }
    return v[index];
}

template<class U>
ostream& operator <<(ostream& outs,const JVector<U>& j){
    for(int i=0;i<j.howMany;++i){
        outs<<j[i]<<" ";
    }
    return outs;
}


#endif // JVECTOR_H
