#ifndef _FMSynth_H_
#define _FMSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "synth.h"
//          is a 
class FmSynth : public Synth {
    public:
        FmSynth(double samplerate);
        ~FmSynth();

        // void modulator(); //fm modulator double the freq of modulator
        void calculate(); 
        double getSample();
        Oscillator* modulator;
        Oscillator* carrier;

    protected:
        double modFreq;

};
#endif