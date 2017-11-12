#include "system.h"

System::System(){

}

System::System(const JVector<Particle> &p){
    sys=p;
    JVector<Particle>::Iterator it = sys.Begin();

}

System& System::operator =(const System &RHS){
    if(this==&RHS){
        return *this;
    }

    sys = RHS.sys;
}

void System::Step(){
//    cout<<"In SysStep\n";
    for(JVector<Particle>::Iterator it = sys.Begin();it!=sys.End();++it){
        it->UpdateV();
    }
}

void System::Draw(sf::RenderWindow& window){
    for(JVector<Particle>::Iterator it = sys.Begin();it!=sys.End();++it){
        it->Draw(window);
    }
}
