#ifndef _FmSynth_H_
#define _FmSynth_H_
#include <iostream>
#include "synth.h"

class FmSynth : public Synth {
    public:
        FmSynth();
        ~FmSynth();

        double getSample();
        void calculate();
};

#endif