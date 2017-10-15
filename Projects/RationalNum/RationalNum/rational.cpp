#include "rational.h"



rational::rational(){
}


bool rational::check_fract(){
    if (d == 0)
        return false;
    else
        return true;
}//bool

rational operator + (rational num1,rational num2){
    rational new_fract;
    int n = (num1.n*num2.d)+(num2.n * num1.d);
    int d = num1.d*num2.d;
    rational temp(n, d);
    return temp;
//    new_fract.n = (num1.n*num2.d)+(num2.n * num1.d);
//    new_fract.d = num1.d*num2.d;
//    return new_fract;
    //My code
}

rational operator - (rational num1,rational num2){
    rational new_fract;
    new_fract.n = (num1.n*num2.d)-(num2.n * num1.d);
    new_fract.d = num1.d*num2.d;
    return new_fract;
}

rational operator * (rational num1,rational num2){
    rational new_fract;
    new_fract.n = (num1.n*num2.n);
    new_fract.d = num1.d*num2.d;
    return new_fract;
}

rational operator / (rational num1,rational num2){
    rational new_fract;
    new_fract.n = (num1.n*num2.d);
    new_fract.d = num1.d*num2.n;
    return new_fract;
}

ostream& operator <<(ostream& outs, const rational& num){
    outs<<num.n<<"/"<<num.d;
    return outs;
}

istream& operator >>(istream& ins,rational& num){
    ins>>num.n>>num.op>>num.d;
    if(num.check_fract()==false){
        cout<<"\n UNDEFINED\n";
    }
    return ins;
}



