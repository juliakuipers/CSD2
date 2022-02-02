#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate) : Synth(samplerate){
    std::cout << "SimpleSynth - Constructor \n";
    osc = new Sine(samplerate);
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - Destructor \n";
    delete osc;
    osc = nullptr;
}

void SimpleSynth::calculate(){
    osc->tick();
}

double SimpleSynth::getSample(){
    osc->getSample();
    //std::cout << "SimpleSynth - getSample - osc->getSample() " << osc->getSample() << "\n";
}

void SimpleSynth::mTof(double midi){
    this -> midi = midi;
    osc->setFreq((midi /127.0) * 20000.0);
}