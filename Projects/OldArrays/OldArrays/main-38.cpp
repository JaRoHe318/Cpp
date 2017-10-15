#include <iostream>
using namespace std;
#include "arraynav.h"
#include "twodnav.h"

/*------------------------------------------
*Program Name:2D Array
*Author: J. Hernandez
*Purpose:
*/

const int TOT=100;
const int ROWS =100;
const int COLS=100;

void TwoD();
void OneD();

int main(){
//    OneD();
    TwoD();
    return 0;
}


void OneD(){
    int input[TOT] = {2,4,6,8,10,55};
    int numU = 6;
    ArrayNav a(input,numU);

    char ans;
    int InsertMe;
    int SearchMe;
    int AppendMe;

    //    ArrayNav an;
    //    PartialArray pa;
    //    ArrayNav a((const int[]){2,4,6,8,22,33},6);

    cout<<"\n Enter a command:\n\n [A]ppend, [I]nsert, [D]elete, [S]earch, [L]eft, [R]ight, e[N]d\n\n";

    cout<<endl<<a<<endl;

    while(ans!='N'){
        cout<<" : ";
        cin>>ans;


        switch(ans){
        case 'A':
        case 'a':
            cout<<"Append: ";
            cin>>AppendMe;
            a.Append(AppendMe);
            cout<<endl<<a<<endl;
            break;
        case 'I':
        case 'i':
            cout<<"Insert:";
            cin>>InsertMe;
            a.Insert(InsertMe);
            cout<<endl<<a<<endl;
            break;
        case 'D':
        case 'd':
//            a.Delete();
            cout<<endl<<a<<endl;
            break;
        case 'S':
        case 's':
            cout<<"Search: ";
            cin>>SearchMe;
            a.Search(SearchMe);
            cout<<endl<<a<<endl;
            break;
        case 'L':
        case 'l':
            a.Left();
            cout<<endl<<a<<endl;
            break;
        case 'R':
        case 'r':
            a.Right();
            cout<<endl<<a<<endl;
            break;

        default:
            cout<<"Err, wrong.";
            break;


        } //switch
    } //while


}

void TwoD(){
    char ans;
    int InsertMe;
    int SearchMe;
    int AppendMe;
    int Two[ROWS][COLS]={{0,1,2},{1,2,3,4},{2,3,4,5,6}};
    TwoDNav a(Two,3,5);
    cout<<"\n Enter a command:\n\n [A]ppend, [I]nsert, [D]elete, [S]earch, [L]eft, [R]ight, [U]p, Do[W]n, e[N]d\n\n";
    a.Print();
    while(ans!='N'||ans!='n'){
        cout<<" : ";
        cin>>ans;
        switch(ans){
        case 'U':
        case 'u':
            a.Up();
            a.Print();
            break;
        case 'w':
        case 'W':
            a.Dow();
            a.Print();
            break;
        case 'A':
        case 'a':
            cout<<"Append: ";
            cin>>AppendMe;
            a.Append(AppendMe);
            a.Print();
            break;
        case 'I':
        case 'i':
            cout<<"Insert:";
            cin>>InsertMe;
            a.Insert(InsertMe);
            a.Print();
            break;
        case 'D':
        case 'd':
            a.Delete();
            a.Print();
            break;
            //        case 'S':
            //        case 's':
            //            cout<<"Search: ";
            //            cin>>SearchMe;
            //            a.Search(SearchMe);
            //            a.Print();
            //            break;
        case 'L':
        case 'l':
            a.Left();
            a.Print();
            break;
        case 'R':
        case 'r':
            a.Right();
            a.Print();
            break;
        default:
            cout<<"Err, wrong.";
            break;
        } //switch
    } //while
}//void
