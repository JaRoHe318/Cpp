
#include <iostream>
using namespace std;

#include "jvector.h"
#include "linkedlist.h"

int main(){
    List<int> test;

    test.InsertHead(22);

    test.InsertHead(33);

    cout<<test;

    return 0;
}
