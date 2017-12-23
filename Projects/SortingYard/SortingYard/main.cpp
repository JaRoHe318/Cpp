#include <iostream>
using namespace std;

#include "jqueue.h"
#include "jstack.h"
#include "jtoken.h"
#include "integer.h"
#include "double.h"
#include "op.h"
#include "funct.h"
#include "sortingyard.h"

void PopQ(JQueue<JToken *> &printMe);

int main(){
    cout << "Shitting Yard!" << endl;

    //3*5+3
    JQueue<JToken*> fixMe;
    JQueue<JToken*> test;
//    fixMe.Push(new Integer(70));
//    fixMe.Push(new Op("+"));
//    fixMe.Push(new Integer(71));
//    fixMe.Push(new Op("+"));
//    fixMe.Push(new Integer(72));

    fixMe.Push(new Funct("sin"));
    fixMe.Push(new Op("("));
    fixMe.Push(new Op("x"));
    fixMe.Push(new Op(")"));

    SortingYard sorter(fixMe);
    test=sorter.getFixed();
    PopQ(test);

//    test=fixMe;
//    PopQ(test);

    cout<<"\n===================================================\n\n";
    return 0;
}

void PopQ(JQueue<JToken*> &printMe){

    cout<<"\n\n\n";
    while(!printMe.isEmpty()){
        cout<<*printMe.Pop()<<endl;
    }
    cout<<"\n\n";

}
