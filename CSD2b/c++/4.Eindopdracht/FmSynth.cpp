#include "FmSynth.h"

FmSynth::FmSynth(double samplerate, double amp) : Synth(samplerate, amp){
    std::cout << "FmSynth - constructor \n";
    mod = new Sine(samplerate);
}

FmSynth::~FmSynth(){
    std::cout << "FmSynth - destructor \n";
    delete mod;
    mod = nullptr;
}

void FmSynth::calculate(){
    mod->calculate();
}

//TODO make fmSynth be able to return the sample to main
double FmSynth::getSample(){
    return mod->getSample(); 
}