#include "double.h"

Double::Double(){
}

Double::Double(double value){
    _d=value;
}

Double::Double(string value){
    _d=atof(value.c_str());
}

void Double::Print(ostream &outs) const{
    outs<<_d;
}

int Double::TypeOf(){
    return DOUBLE;
}
double Double::getDouble(){
    return _d;
}
