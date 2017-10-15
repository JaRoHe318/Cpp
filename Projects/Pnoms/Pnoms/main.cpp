#include <iostream>
#include "poly.h"
using namespace std;



int main(){
    cout << "\n\n\n\n======================================================================================================\n\n\n\n";

    T test[10] = {1,0,2,0,1};
    T test2[10] = {1,0,2,1};

    Poly pnom;
    Poly pnom2;
    cout<<"Enter Pnom1:";
    cin>>pnom;
    cout<<endl<<endl<<endl<<"Pnom1:"<<pnom;
    cout<<endl<<endl;

    cout<<"Enter Pnom2:";
    cin>>pnom2;
    cout<<endl<<endl<<endl<<"Pnom2:"<<pnom2;


    if(pnom==pnom2){
        cout<<endl<<endl<<pnom<<" is equal "<<pnom2;
    }





    cout <<"\n\n\n======================================================================================================\n\n";
    return 0;
}
