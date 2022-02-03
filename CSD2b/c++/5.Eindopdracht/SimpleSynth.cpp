#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate) : Synth(samplerate){
    this -> samplerate = samplerate;
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
    // std::cout << "SimpleSynth - calcate - osc->tick() " << osc->tick() << "\n";

}

double SimpleSynth::getSample(){
    sample = osc->getSample();
    std::cout << "SimpleSynth - getSample - sample " << sample << "\n";
    return sample;
}

void SimpleSynth::mTof(double midi){
    this -> midi = midi;
    //std::cout << "SimpleSynth - mTof - midi " << midi <<  "\n";
    osc->setFreq((midi /127.0) * 20000.0);
}