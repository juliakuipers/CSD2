#include "synth.h"
#include "math.h"

Synth::Synth(double samplerate, double midi, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    this -> midi = midi;
    std::cout << "Synth - constructor \n";
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
}

double Synth::mTof(){
    freq = (midi /127) * 20000;
    return freq;
}

