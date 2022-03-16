#ifndef _synth_H_
#define _synth_H_
#include <iostream>
#include "sine.h"

class Synth {
    public:
        Synth(double samplerate, double amp);
        ~Synth();

        virtual void mTof(double midi)= 0; 
        void setAmp();

        virtual double getSample()=0;
        virtual void calculate()=0;

    protected:
        double samplerate;
        double freq;
        double amp;
        double midi; 
        
        //nu is oscillator a member variable of the class 
};

#endif