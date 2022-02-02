#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"


class Sine : public Oscillator {
    public:
        Sine(double samplerate);
        ~Sine();

        void calculate() override;
};

#endif