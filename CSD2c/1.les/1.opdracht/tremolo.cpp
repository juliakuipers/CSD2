#include "tremolo.h"
#include "square.h"

Tremolo::Tremolo(float freq,float samplerate) : Effect(freq,samplerate), modFreq(0), modSignal(0){
    osc = new Square(freq, samplerate);
}

Tremolo::~Tremolo(){
    delete osc;
    osc = nullptr;
}

void Tremolo::setModFreq(float freq){
    //this is used to set the frequency of the modulation
    osc->setFrequency(freq);
}

float Tremolo::calculate(float sample){
    //oscillator is in range [-1,1]
    modSignal = (osc->genNextSample() + 1.0f)*0.5f;
    // std::cout << "Tremolo - calculate - sample  " << sample << "\n";

    //modSignal is in range [0,1]
    return sample * modSignal;
}
