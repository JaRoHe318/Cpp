#ifndef TERM_H
#define TERM_H
#include <iostream>
using namespace std;

#include "sortlist.h"

//class Term{
//public:
//    Term();
//};

struct Term{
    double _coef;
    int _exp;

    Term();
    Term(double coef, int order);

    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);

    friend Term operator + (const Term& lhs, const Term& rhs);
    friend Term operator * (const Term& lhs, const Term& rhs);
    friend Term operator -(const Term& t);
    // Term operator -() const; //unary operator
    friend Term operator -(const Term& lhs, const Term& rhs);
    friend istream& operator >>(istream& ins, Term& t);

    friend ostream& operator <<(ostream& outs, const Term& t);

    //NewShit
    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    //used in Poly division operator

};

#endif // TERM_H
