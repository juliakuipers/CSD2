#include "synth.h"

Synth::Synth(double samplerate){
    this -> samplerate = samplerate;
    std::cout << "Synth - Constructor \n";
}

Synth::~Synth(){
    std::cout << "Synth - Destructor \n";
}

void Synth::tick(){
    calculate();
}

double Synth::nextSample(){
    return getSample();
    // std::cout << "Synth - nextSample - getSample() " << getSample() <<  "\n";
}
