using namespace std;
#include <iostream>
#include <ctime>

#include "list_simple.h"
#include "node.h"

void TestFun();
void Printer(node<int> *marker, List<int> l);



int main(){
    cout <<endl<<endl<< "-------------------------------" << endl;
    srand(time(0));
    
    TestFun();

    
    cout <<endl<<endl<< "-------------------------------" << endl;
    return 0;
}


void Printer(node<int>* marker, List<int> l){
    node<int>* walker = l.Begin();

    cout<<"H-> ";

    if(marker==NULL){

    }else{

        while (walker!=NULL){
            if(walker==marker){
                cout<<"{"<<*walker<<"} ";
                walker = walker->_next;
            }else{
                cout<<"["<<*walker<<"] ";          //print this node
                walker = walker->_next; //go to the next node
            }
        }
    }
    cout<<" ->|||"<<endl;
}

void TestFun(){
    char ans='x';
    int in=0;

    node<int>* marker=NULL;
    List<int> l;

    do{
        cout<<"\n\n [R]andom [A]fter [B]efore [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd e[X]it\n";
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
        case 'D':
            if(marker==NULL){
                break;
            }else{
                marker=l.Delete(marker);
            }
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
