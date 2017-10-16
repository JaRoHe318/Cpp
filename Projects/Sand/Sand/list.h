#ifndef LIST_H
#define LIST_H

using namespace std;
#include <iostream>
#include <assert.h>
#include "functs.h"


template <class T>
class List{

public:
        class Iterator{
        //the nested class
        public:
            friend class List;                  //this will allow List
                                                //  to access the private
                                                //  members of Iterator

            Iterator(T* p = NULL):_ptr(p){

            }     //ctor
            T& operator *(){                    //dereference oprator
                assert(_ptr);
                return *_ptr;
            }

            friend Iterator operator ++(Iterator& it,       //it++
                                        int unused){
                Iterator hold;
                hold = it;
                it._ptr++;
                return hold;
            }
            Iterator& operator ++(){                        //++it
                _ptr++;
                return *this;
            }

            friend bool operator !=(const Iterator& left,   //it != it
                                    const Iterator& right){
                return left._ptr != right._ptr;
            }

        private:
            T* _ptr;                    //pointer being
                                        //  encapsulated
        };

    List(T* array, int size);       //List ctor
    //---------------------------- big three -----------------------------------
    ~List();
    List(const List& other);
    List& operator =(const List& RHS);
    //---------------------------------------------------------------------------
    Iterator Begin() const;         //an iterator to the start of List
    Iterator End() const;           //an iterator to the end of List


private:
//    T* copy_array(T* src, int size);
//    void destroy_array(T* &src);

    T* _a_list;                     //the List raw data
    int _how_many;                  //size of List
};

//=========================================================================

template <class T>
List<T>::List(T* array, int size){
    _a_list = copy_array(array, size);
    _how_many = size;
}
//---- BIG THREE --------------------------------
template <class T>
List<T>::~List(){
//    destroy_array(_a_list);
}

template <class T>
List<T>::List(const List& other){
    _a_list = copy_array(other._a_list, other._how_many);
    _how_many = other._how_many;

}

template <class T>
List<T>& List<T>::operator =(const List& RHS){
    if (this == &RHS) return *this;
    destroy_array(_a_list);
    _a_list = copy_array(RHS._a_list, RHS._how_many);
    _how_many = RHS._how_many;
}
//-----------------------------------------------------



template <class T>
typename List<T>::Iterator List<T>::Begin() const{
    //C++ requires you to use the keyword typename when referring to the Iterator outside
    //      the class declaration
    return Iterator(_a_list);
}

template <class T>
typename List<T>::Iterator List<T>::End() const{
    //probably a terrible idea!
    return Iterator(_a_list+_how_many);
}



#endif // LIST_H
