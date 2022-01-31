#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(double samplerate,double freq,double amp);
        ~Oscillator();

        void waveForm();
        void setFreq(double freq); 
        void setAmp(double amp);
        void calculate();
        double getSample();

    protected:
        double phase;
        double samplerate;
        double freq;
        double amp;
};

#endif