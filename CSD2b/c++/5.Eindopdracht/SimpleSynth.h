#pragma once 
#include <iostream>
#include "synth.h"
//                  SimpleSynth is a synth        
class SimpleSynth : public Synth {
    public: 
        SimpleSynth(double samplerate);
        ~SimpleSynth();

        void calculate() override;
        double getSample() override;
        double mTof(double midi) override;

    protected:
        double freq; 
        double midi;
};