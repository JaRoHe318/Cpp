#ifndef RATIONAL_H
#define RATIONAL_H

using namespace std;
#include <iostream>

class rational{


public:
    rational();

    //friend
    bool check_fract();
    friend rational operator + (rational num1,rational num2);
    friend rational operator - (rational num1,rational num2);
    friend rational operator * (rational num1,rational num2);
    friend rational operator / (rational num1,rational num2);

    friend ostream& operator <<(ostream& outs, const rational& num);
    friend istream& operator >>(istream& ins,rational& num);

private:
    double n,d;
    char op;
};

#endif // RATIONAL_H
