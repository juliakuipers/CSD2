#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator(double freq,double amp) : freq(freq), amp(amp){
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::setFreq(double freq){
    this->freq = freq;
}

void Oscillator::setAmp(double amp){
    this->amp = amp;
}

