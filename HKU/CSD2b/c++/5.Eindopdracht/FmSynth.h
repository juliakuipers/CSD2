#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "synth.h"
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

class FmSynth : public Synth{
    public:
        FmSynth(double samplerate,std::string carrier,std::string modulator);
        ~FmSynth();

        void calculate();
        double getSample();
        void mTof(double midi);

    protected:
        double samplerate;
        double modSig;
        double carFreq;
        std::string carrier;
        std::string modulator;
        Oscillator* mod = nullptr; 
        Oscillator* car = nullptr; 

};

#endif