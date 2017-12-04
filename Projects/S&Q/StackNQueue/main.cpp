#include <iostream>
using namespace std;

#include "jstack.h"
#include "jqueue.h"

void JStackTest();
void JQueueTest();

int main(){
    cout << "\nStackNQueue!\n" << endl;

    cout<<"Testing JStack==============================\n\n\n";
    JStackTest();
    cout<<"Testing JQueue==============================\n\n\n";
    JQueueTest();



    cout<<"\n\n\n\n\n\n\n\n\n";
    return 0;
}

void JStackTest(){
    JStack<int> test;

    for(int i=3;i<10;++i){
        test.Push(i);
    }

    if(test.isEmpty()){
        cout<<"\nTest empty!\n";
    }

    while(!test.isEmpty()){
        cout<<" Popped:"<<test.Pop()<<"\nSize is "<<test.sizeOf()<<"\n\n";
    }

    cout<<test.Top();



}

void JQueueTest(){
    JQueue<int> test;

    test.Push(11);
    test.Push(22);
    test.Push(33);

    cout<<test<<endl;

    cout<<"This was popped:"<<test.Pop()<<"Size is:"<<test.sizeOf()<<endl;

    cout<<"This is now in front:"<<test.Front()<<endl;

    cout<<test;

    while(!test.isEmpty()){
        cout<<"Popping:"<<test.Pop()<<"\nsize is:"<<test.sizeOf()<<endl;
    }

    cout<<test.Front();
}
