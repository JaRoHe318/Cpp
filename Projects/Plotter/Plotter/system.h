#ifndef SYSTEM_H
#define SYSTEM_H

#include "const.h"
<<<<<<< HEAD
#include "plotter.h"
=======
#include "graph.h"
>>>>>>> 9a3b3d39e7f06a9202b2d8f1c1d8842e397c5828

class System{
public:
    System();
    void Draw(sf::RenderWindow& window);
    void Step();
private:
    Graph g1;
    bool rePlot;
};

#endif // SYSTEM_H
