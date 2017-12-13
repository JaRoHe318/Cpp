#include <iostream>
using namespace std;

#include "jqueue.h"
#include "jstack.h"
#include "jtoken.h"
#include "integer.h"
#include "double.h"
#include "op.h"
#include "funct.h"
#include "rpn.h"

void PopQ(JQueue<JToken *> &printMe);

int main(){
    cout << "RPN!" << endl;

    JQueue<JToken*> container;

    container.Push(new Funct("x"));
    //    container.Push(new Double(10));
    container.Push(new Funct("~"));
    container.Push(new Integer(4));
    container.Push(new Integer(2));
    container.Push(new Op("/"));
    container.Push(new Op("*"));
    //    PopQ(container);
    RPN test;

    for(int i=0;i<10;i+=2){
        test.getY(i,container);
        cout<<test.getAnswer();
    }

    //Takes in a Queue of Token Pointers

    cout<<"\n===================================================\n\n";
    return 0;
}


void PopQ(JQueue<JToken*> &printMe){

    cout<<"\n\n\n";
    while(!printMe.isEmpty()){
        cout<<*printMe.Pop();
    }
    cout<<"\n\n";

}
