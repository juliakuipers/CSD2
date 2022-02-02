#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "synth.h"

class SimpleSynth : public Synth{
    public: 
        SimpleSynth(double samplerate);
        ~SimpleSynth();

        void calculate();
        double getSample();
        void mTof(double midi);

    protected:
        double freq; 
        double samplerate;
        double midi;
        Oscillator* osc; 
};

#endif