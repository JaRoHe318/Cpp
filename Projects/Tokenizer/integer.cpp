#include "integer.h"

Integer::Integer(){
}

Integer::Integer(int value){
    i=value;
}

Integer::Integer(string value){
    i = atof(value.c_str());
}

void Integer::Print(ostream &outs) const{
    outs<<i;
}

int Integer::TypeOf(){
    return INTEGER;
}

double Integer::getInteger(){
    return i;
}

priority Integer::getPriority(){

}
