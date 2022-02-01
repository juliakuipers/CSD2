#include "synth.h"
#include "math.h"
//TODO make sure the relationship between oscillator sine and synth checks out 
Synth::Synth(double samplerate, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    std::cout << "Synth - constructor \n";
    osc = new Sine(samplerate);
    //sine = new Sine(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    // delete osc;
    delete osc;
    // osc = nullptr;
    osc = nullptr;
}

void Synth::mTof(double midi){
    //TODO i want a function that updates the pitch
    this -> midi = midi;
    osc->setFreq((midi /127) * 20000);
}

void Synth::setAmp(){
    osc->setAmp(amp);
}

