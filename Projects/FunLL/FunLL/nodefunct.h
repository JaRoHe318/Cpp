#ifndef NODEFUNCT_H
#define NODEFUNCT_H
#include "node.h"


//LinkedList Gen Functs

template<class T>
void PrintLists(Node<T>* head){
    Node<T>* walker = head;
    cout<<"H ->";
    while(walker!=NULL){
        cout<<*walker;  //print this node
        walker = walker->_next; //go to the next item
    }
    cout<<" NULL";
}

template<class T>
void PrintListBackwards(Node<T>* head){
//    while(head);
}

template<class T>
Node<T>* SearchList(Node<T>* head,const T &searchThis){
    Node<T>* w = head;
    while(w!=NULL){
        if(w->_item == searchThis){
            return w;
        }
        w = w->_next;
    }
        return NULL;
}


template<class T>
Node<T>* InsertHead(Node<T>* &head, const T& insertMe){
    Node<T>* temp = new Node<T>(insertMe);
    temp->_next = head;
    head = temp;
    return head;
}

template<class T>
Node<T>* InsertAfter(Node<T>* head,Node<T>* afterThis ,const T &insertThis){


}

template<class T>
Node<T>* InsertBefore(Node<T>* head,Node<T>* beforeThis ,const T &insertThis){

}
template<class T>
Node<T>* PreviousNode(Node<T>* head, Node<T>* prevToThis){

}
template<class T>
T DeleteNode(Node<T>* &head, Node<T>* deleteThis){

}

template<class T>
Node<T>* CopyList(Node<T>* head){

}

template<class T>
void ClearList(Node<T>* &head){

}

template<class T>
T& At(Node<T>* head, int pos){

}

template<class T>
Node<T>* InsertSorted(Node<T>* &head,const T &item, bool ascending=true){

}

template<class T>
Node<T>* InsertSortedAndAdd(Node<T>* &head,const T &item, bool ascedning = true){

}

template<class T>
Node<T>* WhereThisGoes(Node<T>* &head,const T &item, bool ascedning = true){

}

template<class T>
Node<T>* LastNode(Node<T>* head){

}



#endif // NODEFUNCT_H
