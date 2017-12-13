#include "system.h"

System::System(){
    cout<<"\nIn system\n";
}

void System::Draw(sf::RenderWindow &window){
    g.drawGraph(window);
}

void System::Step(){
    g.Update();
}

void System::Pan(char where){
    g.Pan(where);
}

void System::Zoom(char how){

}
void System::setEquation(){
    Tokenizer tokenize;
    tokenize.inputEquation();
    JQueue<JToken*> preFix =tokenize.getEquation();
    SortingYard sort(preFix);
    postFix=sort.getFixed();
    g.setEquation(postFix);
}

void System::setDomain(){

}
