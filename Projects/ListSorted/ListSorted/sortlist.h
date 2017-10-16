#ifndef SORTLIST_H
#define SORTLIST_H

#include "functions.h";

template <class T>
class List{

public:
    class Iterator{
        public:
            friend class List;                              //give access to list to access _ptr
            Iterator(){
                _ptr = NULL;
            }                        //default ctor
            Iterator(node<T>* p);                   //Point Iterator to where p is pointing to
            T& operator *();                        //dereference operator
            T* operator ->();                       //member access operator
            operator bool();                                //casting operator: true if _ptr not NULL
                                                            //      this turned out to be a pain!
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

    List(bool order=true, bool unique=false);                   //CTOR with default args
                                                                //BIG 3:
    ~List();
//    List(const List<T> &copyThis);
//    List& operator =(const List& RHS);

    Iterator Insert(const T& i);                        //Insert i in a sorted manner

    T Delete(List<T>::Iterator iMarker);        //delete node pointed to by marker
    void Print() const;
    Iterator Search(const T &key) const;                //return Iterator to node [key]
    Iterator Prev(Iterator iMarker);                            //previous node to marker

    const T& operator[](int index) const;               //const version of the operator [ ]
    T& operator[](int index);                           //return item at position index
    Iterator Begin() const;                                     //Iterator to the head node
    Iterator End() const;                                       //Iterator to NULL
    Iterator LastNode() const;                                  //Iterator to the last node
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l);
private:
    node<T>* head;
    bool _order;
    bool _unique;

};



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
typename List<T>::Iterator List<T>::InsertHead(T i){
    return Iterator(_insert_head(head, i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertAfter(T i, Iterator iMarker){
    return Iterator(_insertAfter(head, iMarker._ptr,i));
}

template <class T>
typename List<T>::Iterator List<T>::InsertRandom(Iterator iMarker){
    //    iMarker._ptr;
    return Iterator(_insertRand(head,iMarker._ptr));
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(T i, Iterator iMarker){

}

template <class T>
typename List<T>::Iterator List<T>::InsertSorted(T i){

}

//template <class T>
//typename List<T>::Iterator List<T>::Delete(Iterator iMarker){
//    _deleteNode(head,iMarker);
//}

template<class T>
void List<T>::Print()const {
    _print_list(cout, head);
}

template <class T>
typename List<T>::Iterator List<T>::Search(const T& item)const{
    return Iterator(_search_list(head, item));
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
    //    return _lastNode(head);
    return Iterator(_lastNode(head));
}

template<class U>
ostream& operator <<(ostream& outs,const List<U>& l){
    return _print_list(outs, l.head);
}

#endif // SORTLIST_H
