#include "saw.h"
#include "math.h"

Saw::Saw(double samplerate) : Oscillator(samplerate){
  std::cout << "Saw - Constructor\n";
}



Saw::~Saw() {
  std::cout << "Saw - Destructor\n";
}

void Saw::calculate() {
  sample = phase * 2.0 - 1.0;
  sample *= amp;
}

