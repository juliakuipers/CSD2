#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>
//TODO check if synth oscillator relationship checks out 
class Oscillator{
    public:
        Oscillator(double samplerate);
        virtual ~Oscillator();

        void waveForm();
        void calculate();
        void setFreq(double freq); 

    protected:
        double phase;
        double samplerate;
        double freq;

};

#endif