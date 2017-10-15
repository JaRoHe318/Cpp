#ifndef MCOUNTER_H
#define MCOUNTER_H
#include <iomanip>
#include <iostream>
using namespace std;

class MCounter{
public:
    MCounter();
    int add_1();
    int add_10();
    int add_100();
    int add_1000();
    int reset();
    int count() const;
    bool is_error() const;
private:
    int _count;
    const int MAX=9999;
    bool _error;
};

#endif // MCOUNTER_H
