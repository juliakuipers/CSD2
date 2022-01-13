#include "oscillator.h"
#include <iostream>
 //                     initialize this in main
Oscillator::Oscillator(double freq, double samplerate) : freq(freq), amp(amp),sample(0),samplerate(samplerate){
//                                                      should probably find out what happens here exactly 
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

void Oscillator::setFreq(double freq)
{
  this->freq = freq;
}

void Oscillator::setAmp(double amp){
  this->amp = amp;
}

