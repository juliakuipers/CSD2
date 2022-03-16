#include "synth.h"

Synth::Synth() : Synth(120,"f3"){
    std::cout
    <<"Synth Constructor\n";
}

Synth::Synth(int velocity,std::string pitch) : vel(velocity){
    std::cout 
    <<"Synth Constructor (velocity, pitch " 
    << pitch
    << ")\n";
}

Synth::~Synth(){
    std::cout 
    <<"Synth Destructor\n";
}

int Synth::getVel(){
    return vel;
}

// int Synth::velocity(){
    // return 4;
// }
// 
// int Synth::pitch(){
    // return 3;
// }

// void Synth::play(){
    // std::cout 
    // << "Synth is playing at velocity " 
    // << velocity() 
    // <<"\n"
    // << "and pitch "
    // << pitch()
    // << "\n"; //string and in in c out google 
// }

void Synth::fm(){
    std::cout 
    <<"frequency is being modulated\n";
}
