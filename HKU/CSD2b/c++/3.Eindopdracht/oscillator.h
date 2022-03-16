#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
//i think i should use oscillator only to set the freq and amp 

class Oscillator{
    public:
        Oscillator();
        virtual ~Oscillator();

        void setFreq(double freq);
        double getFreq();
        void setAmp(double freq); 
        double getAmp();

        virtual void calculate()=0;
        virtual double getSample()=0;

    protected:
        double amp;
        double freq;
    
};

#endif