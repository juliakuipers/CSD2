#include "square.h"
#include "math.h"
#include <iostream>

Square::Square(double samplerate,double freq) : Oscillator(samplerate,freq), phase(0.0),freq(freq),samplerate(samplerate) {
  std::cout 
  << "Square - constructor"
  << std::endl;
}



Square::~Square() {
  std::cout
  << "Square - destructor"
  << std::endl;
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += freq / samplerate;
  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // square functionality comes here
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
  sample *= amp;
}
