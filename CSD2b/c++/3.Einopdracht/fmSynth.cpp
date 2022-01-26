#include "fmSynth.h"

//sine * modulator 
FmSynth::FmSynth(double samplerate) : Synth(samplerate){
    std::cout << "FmSynth - constructor \n";
    carrier = new Sine(samplerate);
    modulator = new Sine(samplerate);
    modulator->setFreq(220);
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
    //modSignal = modulator->getSample();
    
    carrier->setFreq(modulator->getSample()*440);
    modSignal = carrier->getFreq();

    //std::cout << modSignal << std::endl;

}

double FmSynth::getSample(){
   return carrier->getSample() ;
    
}
