#include "oscillator.h"

Oscillator::Oscillator() : freq(freq), amp(amp){
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::setFreq(double freq){
    this -> freq = freq;
}