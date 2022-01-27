#include "synth.h"
#include "math.h"

Synth::Synth(double samplerate, double midi, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    this -> midi = midi;
    std::cout << "Synth - constructor \n";
    Oscillator* osc = nullptr; 
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    delete osc;
    osc = nullptr;
}

double Synth::mTof(){
    freq = (midi /127) * 20000;
    osc->getFreq(freq);
}


