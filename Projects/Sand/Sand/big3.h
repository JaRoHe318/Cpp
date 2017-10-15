#ifndef BIG3_H
#define BIG3_H

using namespace std;
#include <iostream>
#include <cassert>
#include <cstring>

char* _copy(char* copy_me);
char* _delete_all(char* delete_me);

class abnormal{
public:
    abnormal();
    ~abnormal(); //destructor
    abnormal(const abnormal& other); //copy ctor X x(y) or X x = y
    abnormal& operator =(const abnormal& RHS); //x = y;

    friend ostream& operator << (ostream& outs, const abnormal& n);
    void set(char* s);
    char* _a;
};

abnormal::abnormal(){
    _a = new char[100000000];
    strcpy(_a, "default string");
}
abnormal::~abnormal(){ //destructor
    cout<<"abnormal destructor was called."<<endl;
    _a = _delete_all(_a);
}
abnormal::abnormal(const abnormal& other){
    cout<<"abnormal copy ctor is being called: "<<other<<endl;
    _a= _copy(other._a);
}
abnormal& abnormal::operator =(const abnormal& RHS){
    cout<<"abnormal assignment is being called: "<<RHS<<endl;
    if (this != &RHS){
        //delete my structures..
        _a = _delete_all(_a);
        _a = _copy(RHS._a);
    }
    return *this;
}

void abnormal::set(char* s){
    strcpy(_a, s);
}

ostream& operator << (ostream& outs, const abnormal& printme){
    outs<<"{"<<printme._a<<"}";
    return outs;
}
abnormal return_abnormal(){
    abnormal a;
    a.set("returning abnormal object");
    cout<<"inside the function 'return_abnormal': _a: "<<a<<endl;
    return a;
}

void test(){
    abnormal a;
    a.set("something");
    cout<<"inside the function: _a:"<<a<<endl;
}


//int main(int argc, char *argv[]){
//    cout <<endl<<endl<<endl<< "===================" << endl;

//    abnormal func_ret = return_abnormal();
//    cout<<"Here is what we got back from func: "<<
//    func_ret<<endl;

//    cout <<endl<<endl<<endl<< "===================" << endl;
//    return 0;
//}

char* _copy(char* copy_me){
    char* temp = new char[strlen(copy_me)+1];
    strcpy(temp, copy_me);
    return temp;
}

char* _delete_all(char* delete_me){
    assert (delete_me != NULL);
    delete delete_me;
    return NULL;
}


#endif // BIG3_H
