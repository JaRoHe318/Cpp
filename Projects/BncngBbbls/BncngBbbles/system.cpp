#include "system.h"

System::System(){
}

System::System(const JVector<Particle> &p){
    sys=p;
}

System& System::operator =(const System &RHS){
    if(this==&RHS){
        return *this;
    }
    sys = RHS.sys;
    return *this;
}

void System::setVector(const JVector<Particle> &p){
    sys=p;
}

void System::howMany(int num){
    for(int i =0;i<NUM_BUBBLES;++i){
        sys.PushBack(Particle());
    }
}

void System::Step(){
    for(JVector<Particle>::Iterator it = sys.Begin();it!=sys.End();++it){
        it->UpdateV();
    }
}

void System::Draw(sf::RenderWindow& window){
    for(JVector<Particle>::Iterator it = sys.Begin();it!=sys.End();++it){
        it->Draw(window);
    }
}
