#include "synth.h"

Synth::Synth(double samplerate,std::string carrier,std::string modulator){
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

void Synth::mTof(double midi){
    this -> midi = midi;
    freq = 440 * pow(2 , (midi-69)/12);
}
