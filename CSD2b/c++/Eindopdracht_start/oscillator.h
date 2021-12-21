#include "sine.h"
#include "square.h"
#include <iostream>

class Oscillator {
    public:
        Oscillator(double freq, double samplerate);
        ~Oscillator();

    private:
        double freq;
        double amp;
        double samplerate; 
};
