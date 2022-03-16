#include "synth.h"
#include "math.h"
//TODO make sure the relationship between oscillator sine and synth checks out 
Synth::Synth(double samplerate, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    std::cout << "Synth - constructor \n";
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
}

// void Synth::setAmp(){
//     osc->setAmp(amp);
// }

