

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
    
    const Term& operator [](const int exp) const;
    Term& operator [](const int exp);

    friend Poly operator + (const Poly& left, const Term& t);
    friend Poly operator * (const Poly& left, const Term& t);



    Poly& operator +=(const Term& t);
    Poly& operator *=(const Term& t);

    Poly& operator +=(const Poly& RHS);
    Poly& operator *=(const Poly& RHS);
    Poly& operator -=(const Poly& RHS);
private:
    List<Term> _poly; //descending sorted list
    int _order;

};


Poly::Poly(){
    _order = 10;
    functions a;
    _coefs=a.allocate(_order);//allocate?

}

Poly::Poly(double term_array[], int order){
    _order=order;
    functions a;
    _coefs=a.copy_array(term_array,order);//copyarray?

}

Poly operator %(const Poly& lhs, const Poly& rhs){//He didn't include this, ask
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
