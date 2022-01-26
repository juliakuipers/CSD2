#include "sine.h"
#include "math.h"

Sine::Sine(double samplerate) : Oscillator(), phase(0), sample(0) {
  std::cout << "Sine - constructor\n";
  this -> samplerate = samplerate; //kan in de oscillator 
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way 
  phase += freq / samplerate;

  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  sample = sin(M_PI * 2 * phase) * amp;
}

double Sine::getSample(){
  return sample;
}

