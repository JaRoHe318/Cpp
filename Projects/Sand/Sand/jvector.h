#ifndef JVECTOR_H
#define JVECTOR_H

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
        Iterator(JVector<T>* p=NULL)/*:_ptr(p)*/{

        }

        //dereference operator
        T& operator *(){
//            return _ptr->_item;
        }


        //member access operator
        T* operator ->(){
            return &(_ptr->_item);
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
//            return *this;
        }

        //friend operator: it++
        friend Iterator operator++(Iterator& it, int unused){
//            List<T>::Iterator hold=it;
//            it=it._ptr->_next;
//            return hold;
        }

    private:
        //pointer being encapsulated
        JVector<T>* _ptr;
    };

    JVector();

    JVector(int size, T fullOfThis);

    Iterator Begin() const;

    Iterator End() const;


    Fill (const T item);

private:
    T* v;

};

template<class T>
JVector<T>::JVector(){

}

template<class T>
JVector<T>::JVector(int size, T fullOfThis){
    v = new T[size];


}

template<class T>
Fill(const T item){
//    JVector<T>::Iterator it =

}

template<class T>
typename JVector<T>::Iterator JVector<T>::Begin()const{

}



#endif // JVECTOR_H
