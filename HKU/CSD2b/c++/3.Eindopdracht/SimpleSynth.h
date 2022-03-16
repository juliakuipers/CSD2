#ifndef _SimpleSynth_H_
#define _SimpleSynth_H_
#include <iostream>
#include "oscillator.h"
#include "sine.h"
#include "saw.h"
#include "synth.h"
//          is a 
class SimpleSynth : public Synth {
    public:
        SimpleSynth(double samplerate);
        ~SimpleSynth();
        void calculate();
        double getSample();

        // double getSample();
        Oscillator* oscillator;

};
#endif