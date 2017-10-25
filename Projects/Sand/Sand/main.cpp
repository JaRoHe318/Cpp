using namespace std;
#include <iostream>

#include <vector>

int main(){
    cout<<"\n\n\n\n\n===========================================================\n\n";

    vector<int> n;

    for(int i=0;i<10;i+=2){
        n.push_back(i);
    }

    for(vector<int>::iterator i = n.begin();i<n.end();++i){
        cout<<*i;
    }

    int got = n.

    cout<<"\n\n\n\n\n===========================================================\n\n";
    return 0;
}
