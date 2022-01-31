#ifndef _synth_H_
#define _synth_H_
#include <iostream>
#include "oscillator.h"

class Synth {
    public:
        Synth(double samplerate, double midi, double amp);
        ~Synth();

        void mTof(); 
        void setAmp();
        // void calculate();
        // double getSample();

        //virtual void calculate()=0;

    protected:
        double samplerate;
        double freq;
        double amp;
        double midi; 
        Oscillator* osc = nullptr;
        
        //nu is oscillator a member variable of the class 

        
};

#endif