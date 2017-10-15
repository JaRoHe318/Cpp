using namespace std;
#include <iostream>

#include "node.h"
#include "nodefunct.h"

int main(){
    cout << "\n\n\n\n======================================================================================================\n\n\n\n";

    Node<int>* head = NULL;

    for(int i=0;i<10;i++){
       InsertHead(head, i);
    }

    PrintLists(head);

    cout<<"\n\n It's at: "<<*SearchList(head, 9);


    cout <<"\n\n\n======================================================================================================\n\n";
    return 0;
}
