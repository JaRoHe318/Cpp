#ifndef SYSTEM_H
#define SYSTEM_H

#include "jvector.h"
#include "particle.h"
#include "constants.h"

class System{
public:
    System();
    System(const JVector<Particle> &p);
    System& operator =(const System &RHS);
    void Draw(sf::RenderWindow& window);
    void Step();
    JVector<Particle> sys;
private:

};

#endif // SYSTEM_H
