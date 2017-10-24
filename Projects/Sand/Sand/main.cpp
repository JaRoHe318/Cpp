using namespace std;
#include <iostream>
#include "list.h"

void Printer(List<int>::Iterator marker,List<int> l);

int main(){
    cout<<"\n\n\n\n\n===========================================================\n\n";

    List<int> l;
    List<int>::Iterator it=l.Begin();

    for(int i=0;i<10;i=i+4){
//        it=l.InsertAfter(i,it);
//       it=l.InsertRandom(it);
    }
    cout<<l;

    int sortA = 0;
    int sortB = 0;

    it=l.InsertSorted(sortA);
    it=l.InsertSorted(sortB);

//    cout<<endl<<l<<endl;
    Printer(it,l);


    return 0;
}

void Printer(List<int>::Iterator marker,List<int> l){
    List<int>::Iterator walker = l.Begin();

    cout<<"H-> ";


    while (!walker.is_null()){
        if(marker==NULL||walker==marker||marker==l.Begin()){
            cout<<"{"<<*walker<<"} ";
            ++walker;
        }else{
            cout<<"["<<*walker<<"] ";          //print this node
            ++ walker;
        }
    }
    cout<<" ->|||\n";
}
