#include "saw.h"
#include "math.h"

Saw::Saw(double samplerate) : Oscillator(), phase(0.5), sample(0), samplerate(samplerate) {
  std::cout << "Saw - constructor\n";
  this -> samplerate = samplerate;
}



Saw::~Saw() {
  std::cout << "Saw - destructor\n";
}

void Saw::calculate() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += freq / samplerate;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // calculate saw wave
  sample = phase * 2.0 - 1.0;
  sample *= amp;
}

double Saw::getSample(){
    return sample;
}
