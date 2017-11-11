#ifndef SYSTEM_H
#define SYSTEM_H

#include "jvector.h"
#include "particle.h"
#include "constants.h"

class System{
public:
    System();
    System(const JVector<Particle> &p);
    JVector<Particle> system;

};

#endif // SYSTEM_H
