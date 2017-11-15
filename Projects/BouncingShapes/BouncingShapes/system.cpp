#include "system.h"

System::System(){
    cout<<"In Sys con\n";
    Particle* test = new Circ();
    sys.PushBack(test);
}
//System& System::operator =(const System &RHS){
//    if(this==&RHS){
//        return *this;
//    }
//    sys = RHS.sys;
//    return *this;
//}

void System::howMany(int num){

    for(int i =0;i<NUM_BUBBLES;++i){
//        sys.PushBack();
    }

}

void System::Step(){
    for(JVector<Particle*>::Iterator it = sys.Begin();it!=sys.End();++it){
//        it->UpdateV();
        cout<<"Step\n";
        (*it)->UpdateV();
    }
}

void System::Draw(sf::RenderWindow& window){
    for(JVector<Particle*>::Iterator it = sys.Begin();it!=sys.End();++it){
//        it->Draw(window);
        (*it)->Draw(window);
    }
}
