#pragma once
#include "oscillator.h"
// #include "effect.h"
//sharedcodepath moet kloppen
//git pull origin prep-cc1


class Tremolo
{
    public:
        Tremolo(float freq,float samplerate);
        ~Tremolo();

        void setModFreq(float freq);
        float calculate(float sample);

    private:
        Oscillator* osc = nullptr;
        // float modFreq;
        float modSignal;

};
