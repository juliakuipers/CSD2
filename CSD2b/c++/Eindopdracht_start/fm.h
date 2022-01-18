#include "oscillator.h"

class Fm : public Oscillator {
    public:
        Fm(double samplerate, double freq);
        ~Fm();

        void mod();

        protected:
        double mFreq;

};