#ifndef OP_H
#define OP_H

#include "jtoken.h"

class Op:public JToken{
public:
    Op();
    Op(string op);
    void Print(ostream &outs)const;
    int TypeOf();
    OPType getOp();
private:
OPType _op;
OPType setOPType(string &op);
};

#endif // OP_H
