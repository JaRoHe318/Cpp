#include <iostream>
#include "rational.h"
using namespace std;

/*------------------------------------------
*Program Name: Rational Number Class
*Author: Jason Hernandez
*Purpose: To get comfortable with classes and overloading operators!
*/

int main(){
    rational a, b, mult, div, plus, sub;
    char command;

    cout<<"\n Enter two fractions: \n\n";
    cout<<" Fract a: ";
    cin>>a;

    cout<<" Fract b: ";
    cin>>b;

    mult=a*b;
    div=a/b;
    plus=a+b;
    sub=a-b;

    //        error checking
    if ((a.check_fract() == false)||(b.check_fract()==false)){
        cout<<" Enter correct fractions \n";
    }
    else{
        cout<<" *: "<<mult<<endl
           <<" /: "<<div<<endl<<" +: "<<plus<<endl
          <<" -: "<<sub<<endl;
    }


    do{
        cout<<"\n [A] [B]  e[X]it :";
        cin>>command;
        switch(toupper(command)){
        case 'A':
            cout<<" Fract a: ";
            cin>>a;
            break;
        case 'B':
            cout<<" Fract b: ";
            cin>>b;
            break;
        default:

            break;
        }
        mult=a*b;
        div=a/b;
        plus=a+b;
        sub=a-b;


        //        error checking
        if ((a.check_fract() == false)||(b.check_fract()==false)){
            cout<<" Enter correct fractions \n";
        }
        else{
            cout<<" *: "<<mult<<endl
               <<" /: "<<div<<endl<<" +: "<<plus<<endl
              <<" -: "<<sub<<endl;
        }

    }while(toupper(command)!='X');




    return 0;
}
