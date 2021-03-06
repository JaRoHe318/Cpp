#include "term.h"

Term::Term(){
    _coef=0;
    _exp=0;
}

Term::Term(double coef, int order){
    _coef=coef;
    _exp=order;
}

bool operator ==(const Term& lhs, const Term& rhs){
    return lhs._exp==rhs._exp;
}

bool operator !=(const Term& lhs, const Term& rhs){
    return lhs._exp!=rhs._exp;
}

bool operator >(const Term& lhs, const Term& rhs){
    return lhs._exp>rhs._exp;
}

bool operator >=(const Term& lhs, const Term& rhs){
    return lhs._exp>=rhs._exp;
}

bool operator <(const Term& lhs, const Term& rhs){
    return lhs._exp<rhs._exp;
}

bool operator <=(const Term& lhs, const Term& rhs){
    return lhs._exp<=rhs._exp;
}

//used in Poly division operator
Term operator / (const Term& lhs, const Term& rhs){
    double coef = lhs._coef/rhs._coef;
    int exp = lhs._exp-rhs._exp;
    return (Term(coef,exp));
}

Term operator +(const Term& lhs, const Term& rhs){
    double coef=lhs._coef+rhs._coef;
    return (Term(coef,lhs._exp));
}

Term operator *(const Term& lhs, const Term& rhs){
    int exp =  lhs._exp+rhs._exp;
    double coef = lhs._coef*rhs._coef;
    return(Term(coef,exp));
}

Term operator -(const Term& t){
    return(Term(-t._coef,t._exp));
}

Term operator -(const Term& lhs, const Term& rhs){
    double coef=lhs._coef-rhs._coef;
    return (Term(coef,lhs._exp));
}

istream& operator >>(istream& ins, Term& t){ 
    char var;//var == 'x'
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

Term& Term::operator +=(const Term& rhs){

}

Term& Term::operator -=(const Term& rhs){

}

Term& Term::operator *=(const Term& rhs){

}

Term& Term::operator /=(const Term& rhs){


}
