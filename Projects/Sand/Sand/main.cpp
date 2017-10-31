using namespace std;
#include <iostream>

#include <vector>
#include "jvector.h"
#include "vfunctions.h"

int main(){
    cout<<"\n\n\n\n\n===========================================================\n\n";
    JVector<int> newVArray(10,0);

    int* temp = new int[15];

//    for(int i = 0;i<11;i++){
//        temp[i]=0;
//    }

    newVArray[2]=4;
    cout<<newVArray;




    cout<<"\n\n\n\n\n===========================================================\n\n";
    return 0;
}
