#ifndef SYSTEM_H
#define SYSTEM_H

#include "const.h"
#include "graph.h"

class System{
public:
    System();
    void Draw(sf::RenderWindow& window);
    void Step();
    void Pan(char where);
private:
    Graph g;
    bool rePlot;
};

#endif // SYSTEM_H
