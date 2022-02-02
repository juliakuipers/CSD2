#include "oscillator.h"


class Sine : public Oscillator {
    public:
        Sine(double samplerate);
        ~Sine();

        void calculate() override;
};