#include "op.h"
Op::Op(){
}
Op::Op(string op){
    _op = setOPType(op);
}
OPType Op::setOPType(string &op){
    if(op.length()>0){
        if(op=="+"){
            opPriority=ADD;
            return PLUS;
        }else if(op=="-"){
            opPriority=SUB;
            return MINUS;
        }else if(op=="/"){
            opPriority=DIVIDE;
            return DIV;
        }else if(op=="*"){
            opPriority=TIMES;
            return MULT;
        }else if(op=="^"){
            opPriority=E;
            return EXP;
        }else if(op=="("||op==")"){
            opPriority=PAREN;
            return P;
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


