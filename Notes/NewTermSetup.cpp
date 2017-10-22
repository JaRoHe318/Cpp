#ifndef TERM_H
#define TERM_H
#include "functions.h"

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
    friend Term operator -(const Term& lhs, const Term& rhs);
    friend istream& operator >>(istream& ins, Term& t);
    
    friend ostream& operator <<(ostream& outs, const Term& t);

    //NewShit
    Term& operator +=(const Term& rhs);
    Term& operator -=(const Term& rhs);
    Term& operator *=(const Term& rhs);
    Term& operator /=(const Term& rhs);

    //used in Poly division operator

    // Term operator -() const; //unary operator
};

// #include "term.h"
// ===================================================================================

Term::Term(){
    _coef=0;
    _exp=0;
}

Term::Term(double coef, int order){
    _coef=coef;
    _exp=order;
}

bool operator ==(const Term& lhs, const Term& rhs){
    if(lhs._coef!=rhs._coef||lhs._exp!=rhs._exp){
        return false;

    }else{
        return true;
    }
}

bool operator !=(const Term& lhs, const Term& rhs){
    if(lhs._coef==rhs._coef&&lhs._exp==rhs._exp){
        return false;
    }else{
        return true;
    }
}

bool operator >(const Term& lhs, const Term& rhs){
    if(lhs._exp>rhs._exp){
        return true;
    } else{
        return false;
    }
}

bool operator <(const Term& lhs, const Term& rhs){
    if(lhs._exp<rhs._exp){
        return true;
    } else{
        return false;
    }
}

//used in Poly division operator
Term operator / (const Term& lhs, const Term& rhs){
    T coef = lhs._coef/rhs._coef;
    int exp = lhs._exp-rhs._exp;
    return (Term(coef,exp));
}

Term operator +(const Term& lhs, const Term& rhs){
    assert(lhs._exp==rhs._exp);
    T coef=lhs._coef+rhs._coef;
    return (Term(coef,lhs._exp));
}

Term operator *(const Term& lhs, const Term& rhs){
    int exp =  lhs._exp+rhs._exp;
    T coef = lhs._coef*rhs._coef;
    return(Term(coef,exp));
}

Term operator -(const Term& t){
    return(Term(-t._coef,t._exp));
}

Term operator -(const Term& lhs, const Term& rhs){
    assert(lhs._exp==rhs._exp);
    T coef=lhs._coef-rhs._coef;
    return (Term(coef,lhs._exp));
}

istream& operator >>(istream& ins, Term& t){
    char var;
    ins>>t._coef>>var>>t._exp; //needs a space between _coef and var

    return ins;
}

ostream& operator <<(ostream& outs, const Term& t){
    if(t._exp==0){
        outs<<t._coef;
    }else if(t._coef==0){
        outs<<"";
    }else{
    outs<<t._coef<<"x^"<<t._exp<<" + ";
    }
    return outs;
}

Term::Term& operator +=(const Term& rhs){

}

Term::Term& operator -=(const Term& rhs){

}

Term::Term& operator *=(const Term& rhs){

}

Term::Term& operator /=(const Term& rhs){


}
