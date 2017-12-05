#include <iostream>
using namespace std;

#include "jqueue.h"
#include "jstack.h"
#include "jtoken.h"
#include "integer.h"
#include "double.h"
#include "op.h"
#include "funct.h"

void PopQ(JQueue<JToken *> &printMe);

int main(){
    cout << "Shitting Yard!" << endl;

    //3*5+3
    JQueue<JToken*> fixMe;
    fixMe.Push(new Integer(3));
    fixMe.Push(new Op("*"));
    fixMe.Push(new Integer(5));
    fixMe.Push(new Op("+"));
    fixMe.Push(new Integer(3));

    PopQ(fixMe);

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
