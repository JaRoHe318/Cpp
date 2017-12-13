#include "sortingyard.h"

SortingYard::SortingYard(){

}
SortingYard::SortingYard(JQueue<JToken*> &fixMe){
    startParen=false;
    cout<<"\nlol in SY Process\n";
    JStack<JToken*> OPStack;
    JToken* temp;

    while(!fixMe.isEmpty()){
        switch(fixMe.Front()->TypeOf()){
        case DOUBLE:
        case INTEGER:
            cout<<"\nnum";
            postFix.Push(fixMe.Pop());
            break;
        case OPERATOR:
        case FUNCTION:
            cout<<"\nfun";
            temp=fixMe.Pop();
            checkPriority(temp,OPStack);
            break;
        default:
            break;
        }
    }
    if(!OPStack.isEmpty()){
        temp=OPStack.Pop();
        postFix.Push(temp);
    }

}

void SortingYard::checkPriority(JToken* &check, JStack<JToken*> &OPStack){

    if(check->getPriority()==PAREN){
        if(static_cast<Op*>(check)->getOp()==SP){
            startParen=true;
            OPStack.Push(check);
        }else if(startParen&&static_cast<Op*>(check)->getOp()==EP){
            while(OPStack.Top()->getPriority()!=PAREN){
                postFix.Push(OPStack.Pop());
            }
        }else if(!startParen){
            cout<<"\nMissingParen\n";//should never be called
        }
    }else{
        if(OPStack.isEmpty()){
            OPStack.Push(check);
        }else if(OPStack.Top()->getPriority()>=check->getPriority()){
            postFix.Push(OPStack.Pop());
            OPStack.Push(check);

        }else if(OPStack.Top()->getPriority()<check->getPriority()){
            OPStack.Push(check);
        }
    }
}

JQueue<JToken*> SortingYard::getFixed(){
    return postFix;
}
