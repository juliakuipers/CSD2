#include "FmSynth.h"

FmSynth::FmSynth(double samplerate, double midi, double amp) : Synth(samplerate, midi, amp){
    std::cout << "FmSynth - constructor \n";
    mod = new Sine(samplerate,freq,amp);
}

FmSynth::~FmSynth(){
    std::cout << "FmSynth - destructor \n";
    delete mod;
    mod = nullptr;
}

void FmSynth::calculate(){
    mod->nextSample();
}

//TODO make fmSynth be able to return the sample to main
double FmSynth::getSample(){
    return mod->getSample(); 
}