#ifndef SYSTEM_H
#define SYSTEM_H

#include "consts.h"
#include "graph.h"
#include "tokenizer.h"
#include "sortingyard.h"
#include "rpn.h"

class System{
public:
    System();
    void Draw(sf::RenderWindow& window);
    void Step();
    void Pan(char where);
    void Zoom(char how);
    void setEquation();
    void setDomain();
private:
    Graph g;
    JQueue<JToken*> postFix;
    bool rePlot;//?
};

#endif // SYSTEM_H
