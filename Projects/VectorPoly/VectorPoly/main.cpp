#include <iostream>
#include "jvector.h"
#include "list.h"
using namespace std;

void testList();
void testJVector();
void print (const JVector<int>& v);

int main(){
    cout<<"\n\n\n=================================================\n\n";

//    testJVector();



    cout<<"\n\n\n=================================================\n\n";
    return 0;
}

void testList(){
    List<int> test;

    test.
}

void testJVector(){
    JVector<int> test;

    print(test);

    test.PushBack(5);
    print(test);

    test.PushBack(7);
    print(test);

    test[4]=9;
    print(test);

    test[8]=12;
    print(test);
}

void print (const JVector<int>& v){
    for(JVector<int>::Iterator it = v.Begin();it!=v.End();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
