#ifndef JSTACK_H
#define JSTACK_H


template<class T>
class JStack{
public:
    JStack();

    //Big Thwee
    ~JStack();
    JStack(const JStack<T> &copyThis);
    JStack& operator =(const JStack<T> &RHS);


    void Push(T pushMe);//adds thing to end
    T Pop();//shows and deletes last thing
    T Top();//Shows top
    bool isEmpty();//returns true if empty
    int sizeOf();//returns size of stack


private:
    T* head;
    int capacity;
    int howMany;
};

template <class T>
T* _makeCopy(T* copyThis,int size){
    T* copy=new T[size];
    for(int i=0;i<size;i++){
        copy[i]=copyThis[i];
    }
    return copy;//returns pointer to copied array
}

template <class T>
void _copyArray(T* copyFrom, T* &copyTo, int howMany){
    for(int i=0;i<howMany;++i){
        copyTo[i]=copyFrom[i];
    }
}

template<class T>
JStack<T>::JStack(){
    capacity = 100;
    howMany=0;
    head=new T[capacity];
}

template<class T>
JStack<T>::~JStack(){
    delete []head;
}

template<class T>
JStack<T>::JStack(const JStack<T> &copyThis){
    head = _makeCopy(copyThis,copyThis.capacity);
}

template<class T>
JStack<T>& JStack<T>::operator =(const JStack<T> &RHS){
    if(this==&RHS){
        return *this;
    }
    delete []head;
    head = _makeCopy(RHS.head,RHS.capacity);
    howMany=RHS.howMany;
    return *this;
}

template<class T>
void JStack<T>::Push(T pushMe){
    if(howMany>=capacity){
        T* temp = new T[2*capacity];
        _copyArray(head,temp,howMany);
        delete []head;
        head=temp;
    }
    head[howMany]=pushMe;
    ++howMany;
}

template<class T>
T JStack<T>::Pop(){
    if(howMany>0){
    T popped=head[--howMany];
    return popped;
    }
    cout<<"\nYour stack is empty!\n";
    return NULL;
}

template<class T>
T JStack<T>::Top(){
    return head[howMany-1];
}

template<class T>
bool JStack<T>::isEmpty(){
    if(howMany==0){
        return true;
    }else{
        return false;
    }
}

template<class T>
int JStack<T>::sizeOf(){
    return howMany;
}


#endif // JSTACK_H
