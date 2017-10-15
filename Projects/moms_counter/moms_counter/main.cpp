#include <iostream>
using namespace std;
#include "mcounter.h"

/*Program Name: Mom's Counter
*Author: Jason Hernandez
*Purpose: A light introduction into classes and basic structure.
* I guess to count stuff too.
*/

void display_counter(const MCounter& ct);

int main(){
    char input;
    cout<<"\n\n ====================================================== \n\n";
    MCounter count;
    cout<<" [A]+1000 [S]+100 [D]+10 [F]+1 [R]eset e[X]it \n\n";
    cout<<": "; cin>>input;
    while(toupper(input)!='X'){
        switch(toupper(input)){
        case 'A':
            count.add_1000();
            display_counter(count);
            break;
        case 'S':
            count.add_100();
            display_counter(count);
            break;
        case 'D':
            count.add_10();
            display_counter(count);
            break;
        case 'F':
            count.add_1();
            display_counter(count);
            break;
        case 'R':
            count.reset();
            display_counter(count);
            break;
        default:
            break;
        }//switch
        cout<<": "; cin>>input;
    }//while

    cout<<"\n\n ====================================================== \n\n";
    return 0;
}

void display_counter(const MCounter& ct){
    cout<<"-------"<<endl;
    if (ct.is_error()){
        cout<<"|ERROR|"<<endl;
    }
    else
        cout<<"| "<<setfill('0')<<setw(4)<<ct.count()<<"|"<<endl;
    cout<<"-------"<<endl;
}
