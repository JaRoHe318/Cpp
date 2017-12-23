#ifndef RPN_H
#define RPN_H

#include <cmath>

#include "jqueue.h"
#include "jstack.h"
#include "jtoken.h"
#include "integer.h"
#include "double.h"
#include "op.h"
#include "funct.h"

class RPN{
public:
    RPN();
    RPN(JQueue<JToken*> postFix);
    RPN(double x, JQueue<JToken*> postFix);
    void getY(double x, JQueue<JToken*> postFix);
    double getAnswer();
private:
    double _answer;
    double _x;
    void Process(JQueue<JToken*> &postFix);
    JToken* calculateOP(JToken *num1, JToken *num2, JToken* operate);
    JToken* calculateFun(JToken* num, JToken* funct);

};

#endif // RPN_H
