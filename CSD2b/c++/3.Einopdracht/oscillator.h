#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
#include <iostream>
//i think i should use oscillator only to set the freq and amp 

class Oscillator{
    public:
        Oscillator();
        ~Oscillator();

        void setFreq(double freq);
        void setAmp(double freq); 

    protected:
        double amp;
        double freq;

};

#endif