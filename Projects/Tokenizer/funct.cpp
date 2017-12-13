#include "funct.h"

Funct::Funct(){
}

Funct::Funct(string fun){
_funct=setFunctType(fun);
}

functType Funct::setFunctType(string &fun){
    if(fun.length()>0){
        if(fun=="sin"){
            return SIN;
        }else if(fun=="cos"){
            return COS;
        }else if(fun=="tan"){
            return TAN;
        }else if(fun=="log"){
            return LOG;
        }else if(fun=="~"){
            return UNARY;
        }else if(fun=="sqrt"){
            return SQRT;
        }else if(fun=="ln"){
            return LN;
        }else{
            cout<<"UnkVar";
            //throw err
        }
    }//check len
}

void Funct::Print(ostream &outs) const{
    cout<<_funct;
}

int Funct::TypeOf(){
    return FUNCTION;
}

functType Funct::getFunct(){
    return _funct;
}

priority Funct::getPriority(){
    return FUN;
}
