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
    void setVector(const JVector<Particle> &p);
    void howMany(int num);
    void Draw(sf::RenderWindow& window);
    void Step();
private:
    JVector<Particle> sys;

};

#endif // SYSTEM_H
