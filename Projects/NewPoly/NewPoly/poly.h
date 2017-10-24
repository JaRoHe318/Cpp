#ifndef POLY_H
#define POLY_H

#include "term.h"
#include "sortlist.h"

//class Poly{
//public:
//    Poly();
//};

class Poly{

public:

    Poly();
    Poly(double term_array[], int order);//was int termarray[]?

    //big three?

    //High lvl=================================================

    //% operator? Oh he didn't include any /
    // friend Poly operator %(const Poly& lhs, const Poly& rhs);
    // friend Poly operator /(const Poly& lhs, const Poly& rhs);

    friend Poly operator * (const Poly& left, const Poly& right);
    friend Poly operator -(const Poly& left, const Poly& right);
    friend istream& operator >>(istream& ins, Poly& p);
    // friend istream& operator >> (istream& outs, Poly& print_me);

    friend Poly operator + (const Poly& left, const Poly& right);
    friend ostream& operator << (ostream& outs, const Poly& print_me);

    //Low Level================================================

    friend Poly operator -(const Poly& p);
    // Poly operator -() const;

//    const Term& operator [](const int exp) const;
//    Term& operator [](const int exp);

    friend Poly operator +(const Poly& left, const Term& t);
    friend Poly operator *(const Poly& left, const Term& t);



    Poly& operator +=(const Term& t);
    Poly& operator *=(const Term& t);

    Poly& operator +=(const Poly& RHS);
    Poly& operator *=(const Poly& RHS);
    Poly& operator -=(const Poly& RHS);
private:
    List<Term> _poly; //descending sorted list
    int _order;

};


#endif // POLY_H
