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
    mod->tick();
}


// void FmSynth::nextStep(mTof()){
//     mod->nextStep(mTof());
// }

//TODO make fmSynth be able to return the sample to main
double FmSynth::getSample(){
    // std::cout << mod->getSample() << std::endl;
    return mod->getSample(); 
}