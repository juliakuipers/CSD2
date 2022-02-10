#include "effect.h"

Effect::Effect(float freq, float samplerate): drywet(0.5){
}

Effect::~Effect(){}



// float Effect::calcDryWet(float drywet){
    // return sample*=drywet;
// }

//drywet might be something i can put when i return the sample 

float getSample(float sample){
    // osc->getSample() * (1-drywet);
    process(sample);
    return 0;
}

//effect should return the sample 
//so it needs the virtual function of calculate from tremolo 