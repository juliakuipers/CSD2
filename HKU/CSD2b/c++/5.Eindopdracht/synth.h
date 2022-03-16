#ifndef _synth_H_
#define _synth_H_
#include <iostream>

class Synth{
    public:
        Synth(double samplerate,std::string carrier,std::string modulator);
        virtual ~Synth();

        void tick();
        double nextSample();
        virtual void mTof(double midi) = 0; 
        virtual void calculate() = 0;    
        virtual double getSample() = 0;     

    protected:
    //implement the same relationship as i have with Sine and Oscillator, Synth being oscillator and Simplesynth being sine
        double samplerate;
        double freq;
        double midi;

};

#endif