#include "sortingyard.h"

SortingYard::SortingYard(){

}
SortingYard::SortingYard(JQueue<JToken *> &fixMe){
    Process(fixMe);
}

void SortingYard::Process(JQueue<JToken *> &fixMe){
    cout<<"\nlol in SY Process\n";

    JStack<JToken*> OPStack;

    switch(fixMe.Front()->TypeOf()){
    case DOUBLE:
        postFix.Push(fixMe.Pop());
        break;
    case INTEGER:
        postFix.Push(fixMe.Pop());
        break;
    case OPERATOR:


        break;
    case FUNCTION:

        break;
    }


}

void SortingYard::checkOP(JStack<JToken*> &ops,JQueue<JToken*> &fixMe){
    if(ops.isEmpty()){
        ops.Push(fixMe.Pop());
    }else{
//        switch(static_cast<Op*>(fixMe)->)
    }
}

void SortingYard::checkFun(JStack<JToken*> &fun, JQueue<JToken*> &fixMe){

}
