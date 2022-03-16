#include "sine.h"
#include "math.h"
#include <iostream>

Sine::Sine(double samplerate,double freq,double amp) : Oscillator(samplerate,freq,amp), phase(0.0){
//            phase is something "personal" to the waveform (i think) that's why i chose to set it here
  std::cout 
  << "Sine - constructor"
  << std::endl;
}

Sine::~Sine() {
  std::cout
  << "Sine - destructor"
  << std::endl;
}

void Sine::calculate() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  // all these exept for phase are set in oscillator.h, the caculation is personal to the waveform
  phase += freq / samplerate;
  sample = sin(M_PI * 2 * phase) * amp;
  //i think i can make fm by multiplying the frequency with another sinus 
}

