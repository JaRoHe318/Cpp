#ifndef SYSTEM_H
#define SYSTEM_H

#include "jvector.h"
#include "particle.h"
#include "circ.h"
#include "rect.h"
#include "square.h"
#include "hex.h"

class System{
public:
    System();
    void howMany(int num);
    void Draw(sf::RenderWindow& window);
    void Step();
private:
    JVector<Particle*> sys;

};

#endif // SYSTEM_H
