#include "op.h"
Op::Op(){
}
Op::Op(string op){
    _op = setOPType(op);
}
OPType Op::setOPType(string &op){
    if(op.length()>0){
        if(op=="+"){
            cout<<"+"<<PLUS<<endl;
            opPriority=ADD;
            return PLUS;
            cout<<"\nPlus Found!\n";
        }else if(op=="-"){
            opPriority=SUB;
            return MINUS;
        }else if(op=="/"){
            opPriority=DIVIDE;
            return DIV;
        }else if(op=="*"){
            cout<<"*"<<MULT<<endl;
            opPriority=TIMES;
            return MULT;
        }else if(op=="^"){
            opPriority=E;
            return EXP;
        }else if(op=="("){
            opPriority=PAREN;
            return SP;
        }else if(op==")"){
            opPriority=PAREN;
            return EP;
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
priority Op::getPriority(){
    return opPriority;
}


