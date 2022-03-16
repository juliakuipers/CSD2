#pragma once
#include <iostream>
#include "synth.h"


class MelodyGen{
    public:
        MelodyGen(double samplerate, Synth* synth);
        ~MelodyGen();
        void tick(); 

    private:
        int list[4] = {60,62,64,65};
        int index = 0; 
        int sampleCount = 0;
        double samplerate;
        Synth* synth;
};