#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "sine.h"

class Synth{
    public:
        Synth(double samplerate);
        ~Synth();

        double getSample();
    
    protected:
        double samplerate;
};

#endif