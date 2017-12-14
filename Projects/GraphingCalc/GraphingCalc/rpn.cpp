#include "rpn.h"

RPN::RPN(){

}

RPN::RPN(double x, JQueue<JToken *> postFix){
    _x=x;
    Process(postFix);
}

RPN::RPN(JQueue<JToken *> postFix){
    Process(postFix);
}//con

JToken* RPN::calculateOP(JToken* num1, JToken* num2, JToken* operate){
    double answer=0;
    double a=0;
    double b=0;

    switch(num1->TypeOf()){
    case INTEGER:
        a=static_cast<Integer*>(num1)->getInteger();
        break;
    case DOUBLE:
        a=static_cast<Double*>(num1)->getDouble();
        break;
    }

    switch(num2->TypeOf()){
    case INTEGER:
        b=static_cast<Integer*>(num2)->getInteger();
        break;
    case DOUBLE:
        b=static_cast<Double*>(num2)->getDouble();
        break;
    }

    switch(static_cast<Op*>(operate)->getOp()){
    case PLUS:
        answer=a+b;
        break;
    case MINUS:
        answer=a-b;
        break;
    case MULT:
        answer=a*b;
        break;
    case DIV:
        answer=a/b;
        break;
    case EXP:
        answer=pow(a,b);
        break;
    }

    return new Double(answer);
}

JToken* RPN::calculateFun(JToken *num, JToken *funct){
    double a=0;
    double ans=0;

    switch(num->TypeOf()){
    case INTEGER:
        a=static_cast<Integer*>(num)->getInteger();
        break;
    case DOUBLE:
        a=static_cast<Double*>(num)->getDouble();
        break;
    }

    switch(static_cast<Funct*>(funct)->getFunct()){
    case SIN:
        ans=sin(a);
        break;
    case COS:
        ans=cos(a);
        break;
    case TAN:
        ans=tan(a);
        break;
    case LOG:
        ans=log10(a);
        break;
    case LN:
        ans=log(a);
        break;
    case SQRT:
        ans=sqrt(a);
        break;
    case ABS:
        ans=abs(a);
        break;
    case UNARY:
        ans=-a;
        break;
    }

    return new Double(ans);
}

void RPN::Process(JQueue<JToken*> &postFix){
    JStack<JToken*> nums;
    JToken* num1;
    JToken* num2;
    JToken* operation;

    while(!postFix.isEmpty()){
        switch(postFix.Front()->TypeOf()){
        case DOUBLE:
            nums.Push(postFix.Pop());
            break;
        case INTEGER:
            nums.Push(postFix.Pop());
            break;
        case OPERATOR:
            operation=postFix.Pop();
            num2=nums.Pop();
            num1=nums.Pop();
            nums.Push(calculateOP(num1,num2,operation));
            break;
        case FUNCTION:
            if(static_cast<Funct*>(postFix.Front())->getFunct()==X){
                postFix.Pop();
                nums.Push(new Double(_x));
            }else{
                operation=postFix.Pop();
                num1=nums.Pop();
                nums.Push(calculateFun(num1,operation));
            }
            break;

        }
    }
    if(!nums.isEmpty()){
        _answer=static_cast<Double*>(nums.Pop())->getDouble();
    }

}

void RPN::getY(double x, JQueue<JToken*> postFix){
    _x=x;
    Process(postFix);
}

double RPN::getAnswer(){
    return _answer;
}
