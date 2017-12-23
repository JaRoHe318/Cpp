#ifndef CONSTS_H
#define CONSTS_H

#include <iostream>
using namespace std;
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "jqueue.h"
#include "jvector.h"

enum functType{X,SIN,COS,TAN,CSC,SEC,COT,
               LOG,LN,SQRT,FACTORIAL,ABS,UNARY};
enum OPType{PLUS,MINUS,MULT,DIV,EXP,SP,EP};
enum priority{NUM,SUB=1,ADD=1,DIVIDE=2,TIMES=2,E,FUN,PAREN};

const int INTEGER = 0;
const int DOUBLE = 1;
const int OPERATOR = 2;
const int FUNCTION = 3;

const double SCREEN_WIDTH = 1000;
const double SCREEN_HEIGHT = 600;
const float LINE_WIDTH = 1;
const int NUM_POINTS = 10000;
const int FRAME_RATE = 60;
const int POINT_R=5;


#endif // CONSTS_H
