#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "synth.h"
#include "sine.h"
//#include "oscillator.h"

class SimpleSynth : public Synth{
    public:
        SimpleSynth(double samplerate, double amp);
        ~SimpleSynth();

        double getSample() override;
        void calculate() override;
        void mTof(double midi) override;

    protected:
        Oscillator* osc;
};

#endif