#ifndef NODE_H
#define NODE_H

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node(T item = T());

    template <class U>
    friend ostream& operator <<(ostream& outs, const node<U>& print_me);
};

template <class T>
node<T>::node(T item):_item(item), _next(NULL){

}
template <class U>
ostream& operator <<(ostream& outs, const node<U>& print_me){
//    outs<<"["<<print_me._item<<"]->";
    outs<<print_me._item;
    return outs;
}


template<class U>
ostream& _print_list(ostream &outs, node<U>* head_ptr){
    node<U>* walker = head_ptr;
    outs<<"H-> ";
    while (walker!=NULL){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<" ->|||"<<endl;
    return outs;
}

template <class T>
node<T>* _search_list(node<T>* &head_ptr, const T& item){
    node<T>* w;
    for (w = head_ptr; w!=NULL;w=w->_next){
        if (w->_item == item)
            return w;
    }
    return NULL;
}

template <class T>
node<T>* _insert_head(node<T>* &head_ptr, const T& item){

    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;
    return head_ptr;
}

template <class T>
node<T>* _insertAfter(node<T>* &head, node<T>* afterThis ,const T &insertThis){
    if(afterThis==NULL){
        return _insert_head(head,insertThis);
    }else{
        node<T>* temp = new node<T>(insertThis);
        temp->_next=afterThis->_next;
        afterThis->_next = temp;
        return temp;
    }
}

template<class T>
node<T>* _insertRand(node<T>* &head,node<T>* afterThis){
    int ran=rand() % 100 + 1;
    return _insertAfter(head, afterThis, ran);
}

template<class T>
node<T>* _insertBefore(node<T>* &head,node<T>* beforeThis ,const T &insertThis){

}

template<class T>
node<T>* _previousNode(node<T>* head, node<T>* prevToThis){
    node<T>* walker = head;
    node<T>* stalker = NULL;
    if (prevToThis == head){
        return NULL;
    }
    while (walker!=NULL){
        stalker=walker;
        walker = walker->_next;
        if(walker==prevToThis){
            return stalker;
        }
    }
}

template<class T>
node<T>* _deleteNode(node<T>* &head, node<T>* deleteThis){
    node<T>* temp = deleteThis->_next;
    node<T>* prev = _previousNode(head,deleteThis); //prev should return null if deleteThis is pointing to head

    if(deleteThis==head){//means you are trying to delete head. ALSO
        head=temp;
    }else{
        prev->_next=temp;
        delete deleteThis;
    }
    return head;
}


template<class T>
node<T>* _copyList(node<T>* head){
    T tempItem;
    node<T>* w = head;
    node<T>* copy = NULL;
    node<T>* copyPtr=NULL;

    if(copy==NULL){
        tempItem=w->_item;
        copy=_insert_head(head,tempItem);
        copyPtr=copy;
        w=w->_next;
    }else{
    while(w!=NULL){
        tempItem = w->_item;
        _insertAfter(copy,w,tempItem);
        w=w->_next;
    }
    }
    return copyPtr;
}

template<class T>
node<T>* _lastNode(node<T>* head){
    node<int>* walker = head;

    while (walker!=NULL){
        if(walker->_next==NULL){
            return walker;
        }
        walker = walker->_next;
    }
    return head;
}


template <class T>
void _deleteAll(node<T>* &head){
    node<int>* walker = head;

    while (walker!=NULL){
        _deleteNode(head, walker);
        walker = walker->_next;
    }
}

template <typename T>//insert
node<T>* _InsertSorted(node<T>* &head, T item, bool ascending=true){
    node<T>* w = head;
    node<T>* s = NULL;

    if(head==NULL){
        w=_insert_head(head,item);
    }else{
        while(w!=NULL){
            s=w;
            w=w->_next;
            if(w->_next==NULL){
                _insertAfter(head,s,item);
            }else
            if(w->_item>=item){
                _insertAfter(head,s,item);
            }
        }
    }
}

template <typename T>//insert or add if a dup
node<T>* InsertSorted_and_add(node<T>* &head, T item, bool ascending=true){

}

//node after which this
//    item goes //order: 0 ascending
template <typename T>
node<T>* WhereThisGoes(node<T>* head, T item,bool ascending=true){

}



#endif // NODE_H
