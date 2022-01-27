#ifndef _RmSynth_H_
#define _RmSynth_H_
#include <iostream>
#include "synth.h"

//          Rmsynth is a Synth 
class RmSynth : public Synth {
    public:
        RmSynth();
        ~RmSynth();

        double getSample();
        void calculate();
};

#endif