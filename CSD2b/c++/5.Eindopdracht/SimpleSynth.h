#ifndef _SimpleSynth_H_
#define _SimpleSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

class SimpleSynth{
    public: 
        SimpleSynth(double samplerate,std::string carrier);
        ~SimpleSynth();

        void calculate();
        double getSample();
        void mTof(double midi);

    protected:
        double freq;
        double samplerate;
        double midi;
        std::string carrier;
        Oscillator* osc = nullptr; 
};

#endif