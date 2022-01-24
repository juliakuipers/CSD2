//call sine in here 
//can set frequency in sine because i #include oscillator in sine (i think)
#include "synth.h"


Synth::Synth(double samplerate) : Sine(), samplerate(samplerate){
    std::cout << "Synth - constructor \n";
    Sine sine;
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
}

double Synth::getSample(){
    sine.getSample(); 
}