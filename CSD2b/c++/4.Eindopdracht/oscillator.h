#ifndef _oscillator_H_
#define _oscillator_H_
#include <iostream>
#include "synth.h"
//TODO check if synth oscillator relationship checks out 
class Oscillator : public Synth {
    public:
        Oscillator();
        ~Oscillator();

        void waveForm();
        void calculate();

    protected:
        double phase;

};

#endif