#ifndef FUNCT_H
#define FUNCT_H

#include <string>
#include "jtoken.h"


class Funct:public JToken{
public:
    Funct();
    Funct(string fun);
    void Print(ostream &outs) const;
    int TypeOf();
//    priority getPriority();
    functType getFunct();
private:
    functType _funct;
    functType setFunctType(string &fun);

};

#endif // FUNCT_H
