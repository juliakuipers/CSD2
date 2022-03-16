#include "sine.h"
#include "math.h"
#include <iostream>

Sine::Sine() : Oscillator(freq,amp), phase(0), sample(0) {
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

double Sine::getSample(){
  //std::cout << freq << std::endl;
  return sample;
}

void Sine::calculate() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += freq / samplerate;
  std::cout << samplerate << std::endl;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  sample = sin(M_PI * 2 * phase) * amp;
  

}