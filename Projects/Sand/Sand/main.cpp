using namespace std;
#include <iostream>

template<class T>
struct node{
    T _item;
    node<T>* _next;
    node(T item= T());
    template <class U>//if you have an op in a Template that is being defined outside of this?
    friend ostream& operator<<(ostream& outs, const node<U>& print_me);
};

template<class T>
node<T>::node(T item):_item(item), _next(NULL){

}

template <class U>
ostream& operator<<(ostream& outs, const node<U>& print_me){
    outs<<"["<<print_me._item<<"] ->";
    return outs;
}

template<class T>
node<T>* insert_head(node<T>* &head_ptr, const T& item){
    //1. create a new node(item)
    node<T>* temp = new node<T>(item);
    //2. temp's next points to wehere head is poijnting to:
    temp->_next = head_ptr;
    //3. point head_ptr to this new node:
    head_ptr = temp;
    return head_ptr;
}

template<class T>
void print_lists(node<T>* head_ptr){
    //1. Walker to head_ptr
    node<T>* walker = head_ptr;
    //2. loop and print until walker hits NULL
    cout<<"H ->";
    while(walker!=NULL){
        cout<<*walker;  //print this node
        walker = walker->_next; //go to the next item
    }
    cout<<" NULL";
}


int main(){
    cout << "\n\n\n\n======================================================================================================\n\n\n\n";

    node<int>* head=NULL;
    for(int i=0;i<6;i++){
        insert_head(head, i);
    }


    print_lists(head);




    cout <<"\n\n\n======================================================================================================\n\n";
    return 0;
}
