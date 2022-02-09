#include "tremolo.h"
#include "sine.h" 

Tremolo::Tremolo(float samplerate) : modFreq(0) modSignal(0){
    osc = new Sine(freq, samplerate);
}

Tremolo::~Tremolo(){
    delete osc;
    osc = nullptr;
}

void Tremolo::setModFreq(float freq){
    osc->setFrequency(freq);
}

float Tremolo::process(float sample){
    //oscillator is in range [-1,1]
    float modSignal = (osc->genNextSample() + 1.0f)*0.5f;

    //modSignal is in range [0,1]
    return sample * modSignal;
}