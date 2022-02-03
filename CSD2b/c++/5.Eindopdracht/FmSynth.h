#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"

class FmSynth{
    public:
        FmSynth(double samplerate,std::string carrier,std::string modulator);
        ~FmSynth();

        void calculate();
        double getSample();
        void mTof(double midi);

    protected:
        double freq;
        double samplerate;
        double midi;
        std::string carrier;
        std::string modulator;
        Oscillator* mod = nullptr; 
        Oscillator* car = nullptr; 

};

#endif