#ifndef SORTINGYARD_H
#define SORTINGYARD_H

#include <cmath>

#include "jqueue.h"
#include "jstack.h"
#include "consts.h"
#include "jtoken.h"
#include "integer.h"
#include "double.h"
#include "op.h"
#include "funct.h"

class SortingYard{
public:
    SortingYard();
    SortingYard(JQueue<JToken *> fixMe);
    JQueue<JToken*> getFixed();

private:
    void Process(JQueue<JToken*> &fixMe);
    void checkOP(JStack<JToken*> &ops, JQueue<JToken *> &fixMe);
    void checkFun(JStack<JToken*> &fun, JQueue<JToken *> &fixMe);
    void checkPriority(JToken* &check, JStack<JToken*> &OPStack);
    JQueue<JToken*> postFix;
    bool startParen;

};

#endif // SORTINGYARD_H
