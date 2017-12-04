#include "op.h"

Op::Op(){
}

Op::Op(string op){
    _op = setOPType(op);
}

OPType Op::setOPType(string &op){
    if(op.length()>0){
        if(op=="+"){
            return PLUS;
            cout<<"\nPlus Found!\n";
        }else if(op=="-"){
            return MINUS;
        }else if(op=="/"){
            return DIV;
        }else if(op=="*"){
            return MULT;
        }else if(op=="^"){
            return EXP;
        }else{
            cout<<"\nUNKNOWN OP\n";
        }
    }
}

void Op::Print(ostream &outs)const{
    outs<<_op;
}

int Op::TypeOf(){
    return OPERATOR;
}

OPType Op::getOp(){
    return _op;
}

