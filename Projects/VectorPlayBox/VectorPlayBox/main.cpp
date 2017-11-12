#include <iostream>
using namespace std;

#include "jvector.h"

int main(){
    JVector<int> copyTo;

    JVector<int> copyFrom(10,10);

    copyTo=copyFrom;

    for(JVector<int>::Iterator it=copyTo.Begin();it!=copyTo.End();++it){
        cout<<*it<<endl;
    }


    return 0;
}
