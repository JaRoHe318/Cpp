//cpp file
#include "poly.h"

T *allocate(int size);
T* copy_array(T* src, int size);
T* resize(T* src, int oldSize, int newSize);
void delete_array(T* &a);



//Term Class====================================================
Term::Term(){

}

Term::Term(double coef, int exp){
    _coef=coef;
    _exp=exp;
}

bool operator ==(const Term& lhs, const Term& rhs){
    if(lhs._coef!=rhs._coef||lhs._exp!=rhs._exp){
        cout<<"\n\n NOT EQUAL, ERR \n\n";
        return false;

    }else{
        cout<<"\n\n Equal! \n\n";
        return true;
    }
}

bool operator !=(const Term& lhs, const Term& rhs){
    if(lhs._coef==rhs._coef&&lhs._exp==rhs._exp){
        cout<<"\n\n EQUAL, ERR \n\n";
        return false;
    }else{
        cout<<"\n\n Not equal! \n\n";
        return true;
    }
}

bool operator >(const Term& lhs, const Term& rhs){
    //    if((lhs._coef>rhs._coef&&lhs._exp==rhs._exp)||(lhs._exp>rhs._exp)){
    if(lhs._exp>rhs._exp){
        cout<<"\n\n Left Greater than!\n\n";
        return true;
    } else{
        cout<<"\n\n NOT GREATER \n\n";
        return false;
    }
}

bool operator <(const Term& lhs, const Term& rhs){
    if(lhs._exp<rhs._exp){
        cout<<"\n\n Right Greater than!\n\n";
        return true;
    } else{
        cout<<"\n\n NOT GREATER \n\n";
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
    outs<<t._coef<<"x^"<<t._exp;
    return outs;
}


//Poly Class=====================================================
Poly::Poly(){
    cout<<"\n In poly!\n\n";
    Term a(2,2);
    Term b(2,2);
    Term c;

    cout<<"Input Poly: ";
    cin>>c;
}

Poly::Poly(T* coefs, int order){
    cout<<"in [] \n\n";
    coefs = new T[order];
}

//the BIG 3
Poly::Poly(const Poly& other){
    cout<<"\n\n Copy Const! \n\n";
    _coefs = copy_array(other._coefs,_order);
}
Poly& Poly::operator =(const Poly& rhs){
    cout<<"\n\n Assignment OP"<<rhs<<endl;
    if(this != &rhs){
        delete_array(_coefs);
        _coefs = copy_array(rhs._coefs, _order);
    }
}
 Poly::~Poly(){
    "\n\n I am destroyer of wrlds\n\n";
    delete_array(_coefs);
}




//High lvl(no _coefs)
Poly operator %(const Poly& lhs, const Poly& rhs){
    Poly div = lhs / rhs;
    return lhs - div * rhs;
}
Poly operator /(const Poly& lhs, const Poly& rhs){

}
Poly operator *(const Poly& lhs, const Poly& rhs){

}
Poly operator -(const Poly& lhs, const Poly& rhs){

}

istream& operator >>(istream& ins, Poly& p){
    char ans='y';
    int i=0;
    while (ans!='X'){
        cout<<"\n: ";
        ins>>p;
        i++;
        cout<<"\n\ni: "<<i;
        cout<<"another int? "; cin>>ans;
    }
}

Poly operator +(const Poly& lhs, const Poly& rhs){

}

ostream& operator <<(ostream& outs, const Poly& p){

}





//Low Level (Little Access to _coefs)===========================
Poly operator -(const Poly& p){

}
Term Poly::operator[](int order) const{
    double coefs = _coefs[order];
    return Term(coefs,order);
}
Poly operator *(const Poly& lhs, const Term& t){

}
Poly operator +(const Poly& lhs, const Term& t){

}

bool operator ==(const Poly& lhs, const Poly& rhs){

}

bool operator !=(const Poly& lhs, const Poly& rhs){

}

bool operator >(const Poly& lhs, const Poly& rhs){

}

bool operator <(const Poly& lhs, const Poly& rhs){

}


//Lowest Lvl Functions
T* allocate(int size){
    T* al;
    T* temp;
    al = new T[size];
    temp=al;
    for(int i = 0;i<size;i++){
        *temp=0;
        temp++;
    }


    return al;//returns address of newly created array
}
T* copy_array(T* src, int size){
    T* copy = new T[size];
    T* p;
    p=copy;
    for(int i=0; i<size; i++){
        *p = *src;
        p++;
        src++;
    }
    return copy;//returns address of new array copy
}
T* resize(T* src,int oldSize, int newSize){//takes an array, puts in longer array, deletes old array.
    T* temp;
    T* w;
    w=src;
    temp=allocate(newSize);//allocates new array of 0s
    for(int i = 0;i<oldSize;i++){
        *temp=*w;
        temp++;
        w++;
    }
    delete [] src; // may not need ?
    return temp; //returns location of new array
}
void delete_array(T* &a){
    delete [] a;
}





