#include "SimpleSynth.h"

//sine * modulator 
SimpleSynth::SimpleSynth(double samplerate) : Synth(samplerate){
    std::cout << "SimpleSynth - constructor \n";
    oscillator = new Sine(samplerate);
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - destructor \n";
    delete oscillator;
    oscillator = nullptr;
}

void SimpleSynth::calculate(){
    oscillator->calculate();
}

double SimpleSynth::getSample(){
    return oscillator->getSample();
}