#include "fmSynth.h"

//sine * modulator 
FmSynth::FmSynth(double samplerate) : Synth(samplerate){
    std::cout << "FmSynth - constructor \n";
    carrier = new Sine(samplerate);
    modulator = new Sine(samplerate);
}

FmSynth::~FmSynth(){
    std::cout << "FmSynth - destructor \n";
    delete carrier;
    delete modulator;
    carrier = nullptr;
    modulator = nullptr;
}

void FmSynth::calculate(){
    modulator->calculate();
    carrier->calculate();
    modFreq = modulator->getFreq()*5;

}

double FmSynth::getSample(){
    return carrier->getSample()*modFreq;
}
