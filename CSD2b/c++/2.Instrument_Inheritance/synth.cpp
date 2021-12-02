#include "synth.h"

Synth::Synth(){
    std::cout<<"Synth Constructor\n";
}

Synth::~Synth(){
    std::out<<"Synth Destructor\n";
}

void Synth::play(){
    std::cout 
    << "Synth is playing at velocity :" 
    << velocity 
    << "and the pitch is :"
    << pitch 
    << "\n";
}

void Synth::fm(){
    std::cout<<"frequency is being modulated\n";
}


// class Synth : public Sound {
// public: 
//     Synth();
//     ~Synth();
//     void play();
//     void fm();
//     void envelope();
//     void lfo();

// };

