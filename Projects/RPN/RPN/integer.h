#ifndef INTEGER_H
#define INTEGER_H

//#include <string>
#include "jtoken.h"


class Integer: public JToken{
public:
    Integer();
    Integer(int value);
    Integer(string value);
    void Print(ostream &outs)const;
    int TypeOf();

    priority getPriority();
    double getInteger();
private:
    double i;
};


#endif // INTEGER_H
