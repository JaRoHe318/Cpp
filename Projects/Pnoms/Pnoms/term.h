#ifndef TERM_H
#define TERM_H
#include "functions.h"

class Term{

public:
    double _coef;
    int _exp;

    Term();
    Term(T coef, int exp);

    friend bool operator ==(const Term& lhs, const Term& rhs);
    friend bool operator !=(const Term& lhs, const Term& rhs);
    friend bool operator >(const Term& lhs, const Term& rhs);
    friend bool operator <(const Term& lhs, const Term& rhs);

    //used in Poly division operator
    friend Term operator / (const Term& lhs, const Term& rhs);

    friend Term operator +(const Term& lhs, const Term& t);
    friend Term operator *(const Term& lhs, const Term& rhs);
    friend Term operator -(const Term& t);
    friend Term operator -(const Term& lhs, const Term& rhs);
    friend istream& operator >>(istream& ins, Term& t);

    friend ostream& operator <<(ostream& outs, const Term& t);

};

#endif // TERM_H
