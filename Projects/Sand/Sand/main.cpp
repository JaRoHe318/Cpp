using namespace std;
#include <iostream>

#include <vector>
#include <jvector.h>

int main(){
    cout<<"\n\n\n\n\n===========================================================\n\n";

    int* temp = new int[15];

    for(int i = 0;i<10;i++){
        temp[i]=0;
    }

    for(int i=0;i<10;++i){
        cout<<temp[i]<<" ";
    }


    cout<<"\n\n\n\n\n===========================================================\n\n";
    return 0;
}
