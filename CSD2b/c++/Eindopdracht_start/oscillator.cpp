#include "oscillator.h"
#include <iostream>
 //                     initialize this in main
Oscillator::Oscillator(double samplerate,double freq) : freq(freq), amp(amp),sample(0),samplerate(samplerate){
    std::cout 
    << "Oscillator Constructor"
    << std::endl;
}

Oscillator::~Oscillator(){
    std::cout
    << "Oscillator Destructor"
    << std::endl;
}

//getters and setters

float Oscillator::getSample() {
  return sample;
}

// void Oscillator::setFreq(double freq)
// {
  // this->freq = freq;
// }

void Oscillator::setAmp(double amp){
  this->amp = amp;
}

