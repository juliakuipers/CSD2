#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>

class Oscillator{
    public: 
        Oscillator(double samplerate);
        virtual ~Oscillator();

        virtual void calculate() = 0;
        double getSample();
        void tick();
        void setFreq(double freq);


    protected:
        //double freq;
        double amp; 
        double sample; 
        double phase; 
        double samplerate;
        double freq;

};

#endif