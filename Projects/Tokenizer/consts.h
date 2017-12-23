#ifndef CONSTS_H
#define CONSTS_H

#include "jqueue.h"

enum functType{SIN,COS,TAN,CSC,SEC,COT,
               LOG,LN,SQRT,FACTORIAL,ABS,UNARY};

enum OPType{PLUS,MINUS,MULT,DIV,EXP,P};

enum priority{NUM,SUB,ADD,DIVIDE,TIMES,E,FUN,PAREN};

const int INTEGER = 0;
const int DOUBLE = 1;
const int OPERATOR = 2;
const int FUNCTION = 3;


//Precidence
const int NUMBER = 0;
const int PLUS_MINUS = 1;
const int MULTI_DIV = 2;


#endif // CONSTS_H
