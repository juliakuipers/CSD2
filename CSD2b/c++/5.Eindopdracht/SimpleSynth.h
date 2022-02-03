#ifndef _SimpleSynth_H_
#define _SimpleSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"

class SimpleSynth{
    public: 
        SimpleSynth(double samplerate,std::string carrier);
        ~SimpleSynth();

        void calculate();
        double getSample();
        void mTof(double midi);

    protected:
        double freq;
        std::string carrier;
        double samplerate;
        double midi;
        Oscillator* osc; 
};

#endif