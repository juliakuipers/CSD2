#include "effect.h"

Effect::Effect(float freq, float samplerate) { }

Effect::~Effect(){}



// float Effect::calcDryWet(float drywet){
    // return sample*=drywet;
// }

//drywet might be something i can put when i return the sample 

float Effect::getSample(float sample){
    // osc->getSample() * (1-drywet);

    return process(sample);
}

//effect should return the sample 
//so it needs the virtual function of calculate from tremolo 