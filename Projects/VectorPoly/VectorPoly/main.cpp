#include <iostream>
#include "jvector.h"
#include "list.h"
using namespace std;

void testList();
void testJVector();
void printJVector (const JVector<int>& v);
void printList (const List<int>& l);

int main(){
    cout<<"\n\n\n=================================================\n\n";

//    testJVector();



    cout<<"\n\n\n=================================================\n\n";
    return 0;
}

void testList(){

    List<int> test;

    test[2]=2;




}

void testJVector(){
    JVector<int> test;

    printJVector(test);

    test.PushBack(5);
    printJVector(test);

    test.PushBack(7);
    printJVector(test);

    test[4]=9;
    printJVector(test);

    test[8]=12;
    printJVector(test);
}

void printJVector (const JVector<int>& v){
    for(JVector<int>::Iterator it = v.Begin();it!=v.End();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void printList(const List<int>& l){
    for(List<int>::Iterator it = l.Begin();it!=l.End();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}
