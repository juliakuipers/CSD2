#ifndef _AmSynth_H_
#define _AmSynth_H_
#include <iostream>
#include "synth.h"

class AmSynth : public Synth {
    public:
        AmSynth();
        ~AmSynth();

        double getSample();
        void calculate();
};

#endif