#include "amSynth.h"

AmSynth::AmSynth(double samplerate) : Synth(samplerate){
    std::cout << "SimpleSynth - constructor \n";
    modulator = new Sine(samplerate);
    carrier = new Sine(samplerate);
    modulator->setFreq(110);
}

AmSynth::~AmSynth(){
    std::cout << "SimpleSynth - destructor \n";
    delete carrier;
    delete modulator;
    carrier = nullptr;
    modulator = nullptr;
}

void AmSynth::calculate(){
    modulator->calculate();
    carrier->calculate();  

    carrier->setAmp(modulator->getSample()*0.5); 
}

double AmSynth::getSample(){
    return carrier->getSample();
}