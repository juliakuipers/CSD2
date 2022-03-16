#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate, double amp) : Synth(samplerate, amp){
    std::cout << "SimpleSynth - constructor \n";
    osc = new Sine(samplerate);
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - destructor \n";
    delete osc;
    osc = nullptr;
}

void SimpleSynth::calculate(){
    osc->tick();
}

void SimpleSynth::mTof(double midi){
    //TODO i want a function that updates the pitch
    this -> midi = midi;
    osc->setFreq((midi /127.0) * 20000.0);
}

//TODO make fmSynth be able to return the sample to main
double SimpleSynth::getSample(){
    // std::cout << mod->getSample() << std::endl;
    return osc->getSample() * amp; 
}