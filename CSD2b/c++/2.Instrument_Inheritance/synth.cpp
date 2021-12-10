#include "synth.h"

Synth::Synth(){
    std::cout
    <<"Synth Constructor\n";
}

Synth::~Synth(){
    std::cout 
    <<"Synth Destructor\n";
}

void Synth::pitch(){
    return "f3"
}

int Synth::velocity(){
    return 4;
}

void Synth::play(){
    std::cout 
    << "Synth is playing at velocity " 
    << velocity() 
    <<"\n"
    << "and pitch "
    << pitch()
    << "\n"; //string and in in c out google 
}

void Synth::fm(){
    std::cout 
    <<"frequency is being modulated\n";
}
