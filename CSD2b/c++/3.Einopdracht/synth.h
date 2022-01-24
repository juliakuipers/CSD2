#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "sine.h"

class Synth : public Sine{
    public:
        Synth(double samplerate);
        ~Synth();

        double getSample();
        void calculate();
        // void set();
    
    protected:
        double samplerate;
};

#endif