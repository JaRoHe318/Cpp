#ifndef JTOKEN_H
#define JTOKEN_H

#include <iostream>
using namespace std;

#include <string>
#include "consts.h"

class JToken{
public:
    JToken();
    friend ostream& operator <<(ostream& outs, const JToken& token);

//    friend istream& operator >>(istream& ins, JToken& getToken);input?

    virtual void Print(ostream& outs)const;
    virtual int TypeOf(){} //to enable children to identify themselves
//    virtual priority getPriority(){}//to enable children to get precedence

};

#endif // JTOKEN_H
