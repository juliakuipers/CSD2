#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>

class Oscillator{
    public:
        Oscillator(double samplerate);
        virtual ~Oscillator();

        void nextSample();
        virtual void calculate() = 0;
        //double getSample();
        void setFreq(double freq); 
        void setAmp(double amp);
        double getFreq();
        double getSample();
        void tick();

    protected:
        double phase;
        double samplerate;
        double freq;
        double amp;
        double sample;
};

#endif