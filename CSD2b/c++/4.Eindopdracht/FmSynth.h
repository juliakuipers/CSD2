#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "synth.h"
#include "sine.h"
#include "oscillator.h"

class FmSynth : public Synth {
    public:
        FmSynth(double samplerate);
        ~FmSynth();

        double getSample();
        void calculate();

        Oscillator* mod;
        Oscillator* car; 
};

#endif