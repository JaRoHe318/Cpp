#include "poly.h"

//Poly Class=====================================================
Poly::Poly(){
    _order = 10;
    functions a;
    _coefs=a.allocate(_order);

}

Poly::Poly(T* coefs, int order){
    _order=order;
    functions a;
    _coefs=a.copy_array(coefs,order);

}

//the BIG 3
Poly::Poly(const Poly& other){
    functions calc;
    cout<<"\n\n Copy Const! \n\n";
    _coefs=calc.copy_array(other._coefs,_order);
}

Poly& Poly::operator =(const Poly& rhs){
    functions calc;
    cout<<"\n\n Assignment OP"<<rhs<<endl;
    if(this != &rhs){
        _coefs=calc.delete_array(_coefs);
        _coefs = calc.copy_array(rhs._coefs, rhs._order);
    }
    return *this;
}
Poly::~Poly(){
    functions calc;
    _coefs=calc.delete_array(_coefs);
}




//High lvl(no _coefs)
Poly operator %(const Poly& lhs, const Poly& rhs){
    Poly div = lhs / rhs;
    return lhs - div * rhs;
}
Poly operator /(const Poly& lhs, const Poly& rhs){

    //    return (Poly());
}
Poly operator *(const Poly& lhs, const Poly& rhs){

    //    return (Poly());
}
Poly operator -(const Poly& lhs, const Poly& rhs){
    cout<<"oh";
    //    return (Poly());
}

istream& operator >>(istream& ins, Poly& p){
    Term t;
    cin>>t;
    p._order=t._exp;
    p._coefs[t._exp]=t._coef;
    do{
        cin>>t;
        p._coefs[t._exp]=t._coef;

    }while(t._exp!=0);

    return ins;
}

Poly operator +(const Poly& lhs, const Poly& rhs){
    //    return (Poly());
}

ostream& operator <<(ostream& outs, const Poly& p){
    for(int i=p._order;i>=0;i--){
        outs<<p[i];
    }
    return outs;
}

//Low Level (Little Access to _coefs)===========================
Poly operator -(const Poly& p){
    for(int i=0; i<p._order+1; i++){
        T temp = p._coefs[i];
        p._coefs[i]=-temp;
    }
    return Poly(p._coefs,p._order);
}
Term Poly::operator[](int order) const{
    T coefs = _coefs[order];
    return Term(coefs,order);
}
Poly operator *(const Poly& lhs, const Term& t){

}
Poly operator +(const Poly& lhs, const Term& t){
    if(lhs._order==t._exp){
        Term poly = lhs[t._exp];
        T co = poly._coef+t._coef;
        //        lhs[t._exp]=co;
    }
}

bool operator ==(const Poly& lhs, const Poly& rhs){
    cout<<"in ==";
    int temp = lhs._order;
    int temp2 = rhs._order;
    cout<<"order1: "<<temp;
    cout<<"order2: "<<temp2;

    if(temp!=temp2){
        return false;
    }else if(temp==temp2){
        while(temp>=0){
            if(lhs[temp]!=rhs[temp2]){
                return false;
            }
            temp--;
            temp2--;
            continue;
        }
        return true;
    }
}

bool operator !=(const Poly& lhs, const Poly& rhs){
    if(lhs==rhs){
        return false;
    }else{
        return true;
    }
}

bool operator >(const Poly& lhs, const Poly& rhs){
    if(lhs._order>rhs._order){
        return true;
    }else{
        return false;
    }
}

bool operator <(const Poly& lhs, const Poly& rhs){
    if(lhs>rhs){
        return false;
    }else{
        return true;
    }

}


