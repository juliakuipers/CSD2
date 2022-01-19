#include "synth.h"

class Oscillator : public Synth {
    public: 
        Oscillator(double freq, double amp);
        //frequency in oscillator because 
        ~Oscillator();

        void setFreq(double freq);
        void setAmp(double amp);

    protected: 
        double freq;
        double amp; 
};