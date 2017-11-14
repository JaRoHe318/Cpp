#include "random.h"

int Random::objectCount=0;

Random::Random(){
    objectCount++;
    if (objectCount==1){
        srand(time(0));
    }
}

int Random::Next(int lo, int hi){
    int r = rand()%(hi-lo+1)+lo;
    return r;
}
