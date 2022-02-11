#pragma once
#include "oscillator.h"
#include "effect.h"
//sharedcodepath moet kloppen 
//git pull origin prep-cc1 


class Tremolo : public Effect{
    public:
        Tremolo(float freq,float samplerate);
        ~Tremolo();

        void setModFreq(float freq);

        float process(float sample) override; 

    private:
        Oscillator* osc;
        float modFreq; 
        float modSignal;  

};