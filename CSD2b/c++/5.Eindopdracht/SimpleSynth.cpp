#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate) : Synth(samplerate), freq(freq){
    std::cout << "SimpleSynth - Constructor \n";
    osc = new Sine(samplerate);
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - Destructor \n";
    delete osc;
    osc = nullptr;
}

void SimpleSynth::calculate(){
    mTof(48);
    osc->tick();
}

double SimpleSynth::getSample(){
    osc->getSample();
}

void SimpleSynth::mTof(double midi){
    this -> midi = midi;
    freq = (midi /127.0) * 20000.0;
    std::cout << "SimpleSynth - mTof - freq = " << freq << std::endl;
}