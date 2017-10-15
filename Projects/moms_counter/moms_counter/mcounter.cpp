#include "mcounter.h"



MCounter::MCounter():_count(0),_error(false){

}

int MCounter::add_1(){
    _count+=1;

}
int MCounter::add_10(){
    _count+=10;
}
int MCounter::add_100(){
    _count+=100;
}
int MCounter::add_1000(){
    _count+=1000;
}
int MCounter::reset(){
    _count = 0;
}
int MCounter::count() const{
    return _count;
}
bool MCounter::is_error() const{
    if (_count>MAX){
        return true;
    }
    else{
        return false;
    }
}
