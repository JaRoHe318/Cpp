#ifndef JQUEUE_H
#define JQUEUE_H
//======================================
//THIS IS THE ONE THAT WORKS YOU FUCKER
//=======================================
#include <iostream>
using namespace std;

//This is Node===============================================

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(T item):_item(item), _next(nullptr){
    }

//    template <class U>
//    friend ostream& operator <<(ostream& outs,
//                                const node<U>& print_me){
//        outs<<"["<<print_me._item<<"]->";
//        return outs;
//    }
};

//These are functions========================================

template<class T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis){
    node<T>* walker = head;
    node<T>* stalker = nullptr;
    if (prevToThis == head){
        return nullptr;
    }
    while (walker!=nullptr){
        stalker=walker;
        walker = walker->_next;
        if(walker==prevToThis){
            return stalker;
        }
    }
}

template <class T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item){

    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;
    return head_ptr;
}

template <class T>
node<T>* _insertAfter(node<T>* &head, node<T>* afterThis,
                      const T &insertThis){
    if(afterThis==nullptr){
        return _insert_head(head,insertThis);
    }else{
        node<T>* temp = new node<T>(insertThis);
        temp->_next=afterThis->_next;
        afterThis->_next = temp;
        return temp;
    }
}

template<class T>
node<T>* _deleteNode(node<T>* &head, node<T>* deleteThis){
    node<T>* temp = deleteThis->_next;
    node<T>* prev = _previousNode(head,deleteThis); //prev should return nullptr if deleteThis is pointing to head

    if(deleteThis==head){//means you are trying to delete head. ALSO
        head=temp;
    }else{
        prev->_next=temp;
        delete deleteThis;
    }
    return head;
}

template <class T>
void _deleteAll(node<T>* &head){
    node<T>* walker = head;

    while (walker!=nullptr){
        _deleteNode(head, walker);
        walker = walker->_next;
    }
}

template<class T>
node<T>* _copyList(node<T>* head){
    node<T>* tempNode=nullptr;
    T tempItem;
    node<T>* w = head;
    node<T>* copyPtr=nullptr;
    node<T>* cw = nullptr;

    if(head==nullptr){
        return nullptr;

    }else{
        while(w!=nullptr){
            tempItem = w->_item;
            tempNode = new node<T>(tempItem);
            if(copyPtr==nullptr){
            copyPtr=tempNode;
            cw=copyPtr;
            }else{
            cw->_next=tempNode;

            cw=cw->_next;

            }
            w=w->_next;
        }
    }
    return copyPtr;
}

template<class T>
node<T>* _insertEnd(node<T>* &head, node<T>* afterThis,
                    const T& insertMe){
    node<T>* temp = new node<T>(insertMe);
    if(afterThis==nullptr){
        temp->_next=head;
        head=temp;
        return head;
    }else{
        temp->_next=afterThis->_next;
        afterThis->_next = temp;
        return temp;
    }
}

template<class U>
ostream& _print_list(ostream &outs, node<U>* head_ptr){
    node<U>* walker = head_ptr;
    outs<<"H-> ";
    while (walker!=nullptr){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<" |||"<<endl;
    return outs;
}



//This is JQueue=============================================

template<class T>
class JQueue{
public:
    JQueue();

    //Big Three
    ~JQueue();
    JQueue(const JQueue<T> &copyThis);
    JQueue& operator =(const JQueue<T> &RHS);

    void Push(T pushMe);
    T Pop();
    T Front();
    bool isEmpty();
    int sizeOf();

    template <class U>
    friend ostream& operator <<(ostream& outs,const JQueue<U>& l);

private:
    node<T>* head;
    node<T>* tail;
    int howMany;
};

template<class T>
JQueue<T>::JQueue(){
    head=nullptr;
    tail=nullptr;
    howMany=0;
}

//Big Three
template<class T>
JQueue<T>::~JQueue(){
    _deleteAll(head);
}

template<class T>
JQueue<T>::JQueue(const JQueue<T> &copyThis){
    head=_copyList(copyThis.head);
    howMany=copyThis.howMany;
}

template<class T>
JQueue<T>& JQueue<T>::operator =(const JQueue<T> &RHS){
    if(this==&RHS){
        return *this;
    }
    _deleteAll(head);
    head=_copyList(RHS.head);
    howMany=RHS.howMany;
    return *this;
}

template<class T>
void JQueue<T>::Push(T pushMe){
    tail=_insertEnd(head,tail,pushMe);
    ++howMany;
}

template<class T>
T JQueue<T>::Pop(){
    if(howMany>0){
        T holdThis = head->_item;//copies value of first in Q
        _deleteNode(head,head);//deletes first in Q
        --howMany;
        return holdThis;
    }
    //should never be called
    cout<<"\nYou have an empty Queue\n";
    return 0;
}

template<class T>
T JQueue<T>::Front(){
    if(howMany>0){
    return head->_item;
    }else{
        cout<<"\nYour Queue is empty!\n";//Should never be called
        return 0;
    }
}

template<class T>
bool JQueue<T>::isEmpty(){
    if(howMany==0){
        return true;
    }else{
        return false;
    }
}

template<class T>
int JQueue<T>::sizeOf(){
    return howMany;
}

template<class U>
ostream& operator <<(ostream& outs,const JQueue<U>& l){
    return _print_list(outs, l.head);
}


#endif // JQUEUE_H
