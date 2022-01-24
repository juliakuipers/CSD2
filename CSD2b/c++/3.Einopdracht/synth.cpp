//call sine in here 
//can set frequency in sine because i #include oscillator in sine (i think)
#include "synth.h"

Synth::Synth(double samplerate) : Sine(samplerate),samplerate(samplerate){
    std::cout << "Synth - constructor \n";
    Sine sine(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
}

// void Synth::set(){
    // sine.setFreq(440);
    // sine.setAmp(0.5);
// }

void Synth::calculate(){
    sine.calculate();
}

double Synth::getSample(){
    sine.getSample(); 
}
