#ifndef POLY_H
#define POLY_H
#include "term.h"


class Poly{//==================================================

public:
    Poly();
    Poly(T* coefs, int order);

    //the BIG 3================================================
    Poly(const Poly& other);
    Poly& operator =(const Poly& rhs);
    ~Poly();

    //High lvl=================================================
    friend Poly operator %(const Poly& lhs, const Poly& rhs);
    friend Poly operator /(const Poly& lhs, const Poly& rhs);
    friend Poly operator *(const Poly& lhs, const Poly& rhs);
    friend Poly operator - (const Poly& lhs, const Poly& rhs);
    friend istream& operator >>(istream& ins, Poly& p);

    friend Poly operator +(const Poly& lhs, const Poly& rhs);
    friend ostream& operator <<(ostream& outs, const Poly& p);

    //Low Level================================================
    friend Poly operator -(const Poly& p);
    Term operator[](int order) const;
    friend Poly operator *(const Poly& lhs, const Term& t);
    friend Poly operator +(const Poly& lhs, const Term& t);

    friend bool operator ==(const Poly& lhs, const Poly& rhs);
    friend bool operator !=(const Poly& lhs, const Poly& rhs);
    friend bool operator >(const Poly& lhs, const Poly& rhs);
    friend bool operator <(const Poly& lhs, const Poly& rhs);

    int order() const { //may give trouble?
        return _order;
    }

private:
    void fix_order();//get rid of highest terms with zero coefs
    int _order;
    double* _coefs;

};


#endif // POLY_H
