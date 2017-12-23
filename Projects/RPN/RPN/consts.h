#ifndef CONSTS_H
#define CONSTS_H

enum functType{X,SIN,COS,TAN,CSC,SEC,COT,
               LOG,LN,SQRT,FACTORIAL,ABS,UNARY};

enum OPType{PLUS,MINUS,MULT,DIV,EXP};

enum priority{NUM,SUB=1,ADD=1,DIVIDE=2,TIMES=2,E,FUN,PAREN};

const int INTEGER = 0;
const int DOUBLE = 1;
const int OPERATOR = 2;
const int FUNCTION = 3;


//Precidence
const int NUMBER = 0;
const int PLUS_MINUS = 1;
const int MULTI_DIV = 2;


#endif // CONSTS_H
