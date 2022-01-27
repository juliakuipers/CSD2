#ifndef _synth_H_
#define _synth_H_
#include <iostream>
#include "oscillator.h"

class Synth {
    public:
        Synth(double samplerate, double midi, double amp);
        ~Synth();

        double mTof(); 

        //virtual void calculate()=0;

    protected:
        double samplerate;
        double freq;
        double amp;
        double midi; 
        
};

#endif