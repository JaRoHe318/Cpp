using namespace std;
#include <iostream>
#include "list.h"

int main(){
    cout<<endl<<endl<<"Testing a list of ints:"<<endl;
    int a[] = {1,1,3,5,8,13};           //an array! (sorry about this!)

    List<int> list(a, 6);               //instantiate a List object



    List<int>::Iterator it;             //a List Itertor object
    for (it=list.Begin(); it!=list.End(); it++){//postfix ++
        //looping through all the elements of List using the Iterator
        cout<<*it<<"|";
    }

    //delete it;      //cannot be done.
    //delete it._ptr; //cannot be done.

    cout<<endl<<endl<<"Testing a list of strings:"<<endl;

    string s[] = {string("Curly"), string("Moe"), string("Larry")};
    List<string> slist(s, 3);
    List<string>::Iterator sit;           //a List Itertor object
    for (sit=slist.Begin();
         sit!=slist.End();
         ++sit){                          //prefix ++
        //looping through all the elements of List using the Iterator
        cout<<*sit<<"|";
    }

    cout <<endl<<endl<< "=======================" << endl<<endl;
    return 0;
}
