#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "sine.h"

class Synth : public Sine{
    public:
        Synth(double samplerate);
        ~Synth();

        double getSample();
        void calculate();
        void waveForm();
        void set();
    
    protected:
        double samplerate;
        Sine* osc = nullptr;
};

#endif