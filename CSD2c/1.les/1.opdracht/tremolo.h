#pragma once
#include "oscillator.h"
//sharedcodepath moet kloppen 
//git pull origin prep-cc1 


class Tremolo{
    public:
        Tremolo(float samplerate);
        ~Tremolo();

        void setModFreq(float freq);
        float process(float sample); 

    private:
        Oscillator* osc;
        float modFreq; 
        float modSignal;  

};