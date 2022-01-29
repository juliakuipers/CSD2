#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(double samplerate);
        ~Oscillator();

        void waveForm();
        void calculate();
        void setFreq(double freq); 
        void setAmp(double amp);
        virtual double getSample()=0;

    protected:
        double phase;
        double samplerate;
        double freq;
        double amp;
};

#endif