#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <stdlib.h>

class Random{
public:
    Random();
    int Next(int lo, int hi);
private:
    static int objectCount;
};

#endif // RANDOM_H
