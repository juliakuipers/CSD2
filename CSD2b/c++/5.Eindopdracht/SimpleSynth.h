#pragma once 
#include <iostream>
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
//                  SimpleSynth is a synth        
class SimpleSynth : public Synth {
    public: 
        SimpleSynth(double samplerate);
        ~SimpleSynth();

        void calculate() override;
        double getSample() override;
        void mTof(double midi) override;

    protected:
        double freq; 
        double midi;
        Oscillator* osc; 
};