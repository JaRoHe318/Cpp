#ifndef DOUBLE_H
#define DOUBLE_H

#include "jtoken.h"

class Double:public JToken{
public:
    Double();
    Double(double value);
    Double(string value);
    virtual void Print(ostream& outs) const;
    int TypeOf();
    priority getPriority();
    double getDouble();
private:
    double _d;
};

#endif // DOUBLE_H
