#ifndef _AmSynth_H_
#define _AmSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "synth.h"

class AmSynth : public Synth {
    public:
        AmSynth(double samplerate);
        ~AmSynth();
        void calculate();
        double getSample();

        Oscillator* modulator;
        Oscillator* carrier;

};


#endif