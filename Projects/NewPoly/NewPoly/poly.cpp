#include "poly.h"

Poly::Poly(){
    _order = 0;
}

Poly::Poly(double term_array[], int order){
    _order=order;
    int tempOrder = order;
    Term temp;

    for(int i=0;i<=order;i++){
       temp._coef=term_array[i];
       temp._exp = tempOrder;
//       cout<<temp;
       _poly.InsertSorted(temp);
       tempOrder--;
    }

}

//Poly operator %(const Poly& lhs, const Poly& rhs){//He didn't include this, ask
//    Poly div = lhs / rhs;
//    return lhs - div * rhs;
//}

//Poly operator /(const Poly& lhs, const Poly& rhs){

//    //    return (Poly());
//}

//Poly operator *(const Poly& lhs, const Poly& rhs){

//    //    return (Poly());
//}

//Poly operator -(const Poly& lhs, const Poly& rhs){
//    cout<<"oh";
//    //    return (Poly());
//}


//istream& operator >>(istream& ins, Poly& p){
//    Term t;
//    cin>>t;
//    p._order=t._exp;
//    p._coefs[t._exp]=t._coef;
//    do{
//        cin>>t;
//        p._coefs[t._exp]=t._coef;
//    }while(t._exp!=0);
//    return ins;
//}

istream& operator >>(istream& ins, Poly& p){
    Term chunk;
        ins>>chunk;
}


Poly operator +(const Poly& lhs, const Poly& rhs){
    //    return (Poly());
}

//ostream& operator <<(ostream& outs, const Poly& p){
//    for(int i=p._order;i>=0;i--){
//        outs<<p.Poly._poly.
//    }
//              return outs;
//    }

ostream& operator <<(ostream& outs, const Poly& p){
    p._poly.Print();
}

//Low Level (Little Access to _coefs)===========================
//Poly operator -(const Poly& p){
//    for(int i=0; i<p._order+1; i++){
//        T temp = p._coefs[i];
//        p._coefs[i]=-temp;
//    }
//    return Poly(p._coefs,p._order);
//}
//Term Poly::operator[](int order) const{
//    T coefs = _coefs[order];
//    return Term(coefs,order);
//}
//Poly operator *(const Poly& lhs, const Term& t){

//}
//Poly operator +(const Poly& lhs, const Term& t){
//    if(lhs._order==t._exp){
//        Term poly = lhs[t._exp];
//        T co = poly._coef+t._coef;
//        //        lhs[t._exp]=co;
//    }
//}


//Low Level (Little Access to _coefs)===========================
Poly operator -(const Poly& p){
    for(int i=0; i<p._order+1; i++){
        //        double temp = p._coefs[i];
        //        p._coefs[i]=-temp;
        //    }
        //    return Poly(p._coefs,p._order);
    }
}

//Term Poly::operator[](int order) const{
//    double coefs = _coefs[order];
//    return Term(coefs,order);
//}

Poly operator *(const Poly& lhs, const Term& t){

}

Poly operator +(const Poly& lhs, const Term& t){
    //    if(lhs._order==t._exp){
    //        Term poly = lhs[t._exp];
    //        T co = poly._coef+t._coef;
    //        lhs[t._exp]=co;
    //    }
}
