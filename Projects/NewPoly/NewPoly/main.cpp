#include <iostream>
using namespace std;

#include "sortlist.h"
#include "poly.h"

int main(){
    cout<<"\n\n\n\n\n==============================================\n\n";
    double a[]={4,3,2,1};
//    double a[]={7,3,5,8};
    Poly newP(a,3);

    cout<<newP;


    return 0;
}
