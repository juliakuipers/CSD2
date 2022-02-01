#include "synth.h"
#include "math.h"
//TODO make sure the relationship between oscillator sine and synth checks out 
Synth::Synth(double samplerate, double midi, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    this -> midi = midi;
    std::cout << "Synth - constructor \n";
    osc = new Sine(samplerate,freq,amp);
    //sine = new Sine(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    // delete osc;
    delete osc;
    // osc = nullptr;
    osc = nullptr;
}

void Synth::mTof(){
    freq = (midi /127) * 20000;
    osc->setFreq(freq);
}

void Synth::setAmp(){
    osc->setAmp(amp);
}

