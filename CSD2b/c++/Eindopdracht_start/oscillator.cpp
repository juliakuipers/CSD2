#include "oscillator.h"
 //                     initialize this in main
Oscillator::Oscillator(double freq, double samplerate) : freq(freq), amp(0.5), samplerate(samplerate){
    std::cout 
    << "Oscillator Constructor"
    << std::endl;
}

Oscillator::~Oscillator(){
    std::cout
    << "Oscillator Destructor"
    << std::endl;
}
