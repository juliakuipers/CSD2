#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_
//#include "sine.h"
//#include "square.h"
#include <iostream>
//something going wrong probably with the hashtags 


class Oscillator {
    public:
        Oscillator(double freq, double samplerate);
        //both freq and samplerate get initialized in main
        ~Oscillator(); 

        void setFreq(double freq);
        void setAmp(double amp);
        float getSample();

    protected:
    
        double freq;
        double amp;
        double samplerate; 
        double sample; 
};
#endif