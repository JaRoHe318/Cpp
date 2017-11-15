#include <iostream>
using namespace std;

#include "jstack.h"
//#include "

int main(){
    cout << "\nStackNQueue!\n" << endl;

    JStack<int> test;

    for(int i=3;i<10;++i){
        test.Push(i);
    }

    if(test.isEmpty()){
        cout<<"\nTest empty!\n";
    }

    for(int i=0;i<10;++i){
        cout<<" Popped:"<<test.Pop()<<" Size is "<<test.sizeOf()<<"\n";
    }

    cout<<test.Top();

    if(test.isEmpty()){
        cout<<"\n\nTest empty!\n";
    }


    cout<<"\n\n\n\n\n\n\n\n\n";
    return 0;
}
