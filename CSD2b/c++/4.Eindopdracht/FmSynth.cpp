#include "FmSynth.h"

FmSynth::FmSynth(double samplerate, double midi, double amp) : Synth(samplerate, midi, amp){
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
    mod->getSample(); 
}