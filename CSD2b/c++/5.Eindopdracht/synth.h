#ifndef _synth_H_
#define _synth_H_
#include <iostream>

class Synth{
    public:
        Synth(double samplerate);
        virtual ~Synth();

        void tick();
        double nextSample();
        void mTof(double midi); 
        virtual void calculate() = 0;    
        virtual double getSample() = 0;     

    protected:
    //implement the same relationship as i have with Sine and Oscillator, Synth being oscillator and Simplesynth being sine
        double samplerate;

};

#endif