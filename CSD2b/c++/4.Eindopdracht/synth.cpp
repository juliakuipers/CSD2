#include "synth.h"
#include "math.h"
//TODO make sure the relationship between oscillator sine and synth checks out 
Synth::Synth(double samplerate, double midi, double amp){
    this -> samplerate = samplerate;
    this -> amp = amp;
    this -> midi = midi;
    std::cout << "Synth - constructor \n";
    sine = new Sine(samplerate);
    //osc = new Oscillator(samplerate);
    //sine = new Sine(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    // delete osc;
    delete sine;
    // osc = nullptr;
    sine = nullptr;
}

void Synth::mTof(){
    freq = (midi /127) * 20000;
    sine->setFreq(freq);
}

void Synth::setAmp(){
    sine->setAmp(amp);
}

void Synth::calculate(){
    sine->calculate();
}


double getSample(){
    sine->getSample();
}
