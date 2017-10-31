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

        Iterator(typename JVector<T>::Iterator it):_ptr(it){

        }
    private:
        JVector<T>* _ptr;
        int pos;

    };//Iterator

};//list



#endif // LIST_H
