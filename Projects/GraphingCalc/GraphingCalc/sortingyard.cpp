#include "sortingyard.h"

SortingYard::SortingYard(){
    startParen=false;
}
SortingYard::SortingYard(JQueue<JToken*> fixMe){
    startParen=false;
    JStack<JToken*> OPStack;
    JToken* temp;

    while(!fixMe.isEmpty()){
        switch(fixMe.Front()->TypeOf()){
        case DOUBLE:
        case INTEGER:
            postFix.Push(fixMe.Pop());
            break;
        case OPERATOR:
        case FUNCTION:
            if(fixMe.Front()->getPriority()==NUM){
                postFix.Push(fixMe.Pop());
            }else{
                temp=fixMe.Pop();
                checkPriority(temp,OPStack);
            }
            break;
        default:
            break;
        }
    }
    if(!OPStack.isEmpty()){
        if(OPStack.Top()->getPriority()==PAREN){
            OPStack.Pop();
        }else{
            temp=OPStack.Pop();
            postFix.Push(temp);
        }
    }
}

void SortingYard::checkPriority(JToken* &check, JStack<JToken*> &OPStack){

    if(!startParen&&check->getPriority()==PAREN){
        if(static_cast<Op*>(check)->getOp()==SP){
            startParen=true;
            OPStack.Push(check);
        }else if(!startParen){
            cout<<"\nMissingParen\n";//should never be called
        }

    }else if(startParen&&check->getPriority()==PAREN){
        if(OPStack.Top()->getPriority()==PAREN){
            OPStack.Pop();
        }else if(static_cast<Op*>(check)->getOp()==EP){
            while(!OPStack.isEmpty()){
                postFix.Push(OPStack.Pop());
            }
            startParen=false;
        }

    }else if(startParen){
        OPStack.Push(check);

    }else{
        if(OPStack.isEmpty()){
            OPStack.Push(check);
        }else if(OPStack.Top()->getPriority()>=check->getPriority()){
            if(OPStack.Top()->getPriority()==PAREN){

            }else{
                postFix.Push(OPStack.Pop());
                OPStack.Push(check);
            }

        }else if(OPStack.Top()->getPriority()<check->getPriority()){
            OPStack.Push(check);
        }
    }
}

JQueue<JToken*> SortingYard::getFixed(){
    return postFix;
}
