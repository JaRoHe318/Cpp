using namespace std;
#include <iostream>
#include <ctime>
<<<<<<< HEAD

=======
>>>>>>> bffa3538466a792e78f990eb2f63cae2380b673e
#include "list.h"
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

<<<<<<< HEAD
=======

>>>>>>> bffa3538466a792e78f990eb2f63cae2380b673e
void Printer(node<int>* marker,List<int> l){
    node<int>* walker = l.Begin();

    cout<<"H-> ";

    if(marker==NULL){
        //cout<<"NULL!";
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
    node<int>* temp = NULL;
    List<int> l;
    List<int> c;

    Printer(marker,l);
    do{
        cout<<"\n\n [R]andom [A]fter [B]efore [D]elete [S]earch [P]revious  [N]ext  [H]ome  [E]nd e[X]it\n";
        cout<<": "; cin>>ans;

        switch (toupper(ans)) {
        case 'R':
            marker=l.InsertRandom(marker);
            break;
<<<<<<< HEAD
        case 'C':
            temp = c.Copy(l);

            cout<<"\n=================\n";
            cout<<c;
            cout<<"\n=================";
            break;
=======
//        case 'C':
//            cout<<"\n\n";
//            Printer(marker,l);

////            c.Copy(c);

//            cout<<"\n\n";
//            Printer(marker,c);
>>>>>>> bffa3538466a792e78f990eb2f63cae2380b673e
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
