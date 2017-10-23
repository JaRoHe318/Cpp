using namespace std;
#include <iostream>
#include <ctime>

#include "list.h"
#include "node.h"

void TestFun();
void Printer(List<int>::Iterator marker, List<int> l);



int main(){
    cout <<endl<<endl<< "-------------------------------" << endl;
    srand(time(0));

    TestFun();

    cout <<endl<<endl<< "-------------------------------" << endl;
    return 0;
}

void Printer(List<int>::Iterator marker,List<int> l){
    List<int>::Iterator walker = l.Begin();

    cout<<"H-> ";

    if(walker.is_null()){

    }

    while (!walker.is_null()){
        if(walker==marker||marker==NULL||marker==l.Begin()){
            cout<<"{"<<*walker<<"} ";
            ++walker;
        }else{
            cout<<"["<<*walker<<"] ";          //print this node
            ++walker;
        }
    }
    cout<<" ->|||\n";
}


void TestFun(){
    char ans='x';
    int in=0;

    List<int> l;
    List<int>::Iterator marker=l.Begin();

    do{
        cout<<"\n\n [R]andom [A]fter [B]efore [S]earch [P]revious  [N]ext  [H]ome  [E]nd e[X]it\n";
        cout<<": "; cin>>ans;

        switch (toupper(ans)) {
        case 'R':
            marker=l.InsertRandom(marker);
            break;
        case 'A':
            cout<<": "; cin>>in;
            marker=l.InsertAfter(in, marker);
            break;
        case 'B':
            cout<<": "; cin>>in;
            marker=l.InsertBefore(in,marker);
            break;
        case 'S':
            cout<<": "; cin>>in;
            marker=l.Search(in);
            break;
        case 'P':
            marker=l.Prev(marker);
            break;
        case 'N':
            marker=l.Next(marker);
            break;
        case 'H':
            marker=l.Begin();
            break;
        case 'E':
            marker=l.End();
            break;
        default:
            break;
        }
        Printer(marker,l);
    }while(ans!='x');
}
