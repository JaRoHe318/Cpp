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
//    char getFunct();
    functType getFunct();
private:
//    char _funct;
    functType _funct;
    functType setFunctType(string &fun);

};

#endif // FUNCT_H
