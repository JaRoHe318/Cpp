#include "poly.h"

Poly::Poly(){
    _order = 0;
}

Poly::Poly(double term_array[], int order){
    _order=order;
    int tempOrder = order;
    for(int i=0;i<=order;i++){
        _poly.InsertSorted(Term(term_array[i],tempOrder));
        tempOrder--;
    }

}

Poly operator %(const Poly& lhs, const Poly& rhs){//He didn't include this, ask
//    Poly div = lhs / rhs;
//    return lhs - div * rhs;
}

Poly operator /(const Poly& lhs, const Poly& rhs){
}


Poly operator -(const Poly& lhs, const Poly& rhs){

}

istream& operator >>(istream& ins, Poly& p){

}


Poly operator +(const Poly& lhs, const Poly& rhs){

}

ostream& operator <<(ostream& outs, const Poly& p){
    p._poly.Print();
}

//Low Level (Little Access to _coefs)===========================

Poly operator +(const Poly& lhs, const Term& t){
    if(lhs._order==t._exp){

    }

}


//Low Level (Little Access to _coefs)===========================
Poly operator -(const Poly& p){
    for(int i=0; i<p._order+1; i++){
        //        double temp = p._coefs[i];
        //        p._coefs[i]=-temp;
        //    }
        //    return Poly(p._coefs,p._order);
    }
}

Poly operator *(const Poly& lhs, const Term& t){

}
