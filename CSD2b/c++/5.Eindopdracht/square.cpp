#include "square.h"
#include "math.h"

Square::Square(double samplerate) : Oscillator(samplerate){
  std::cout << "Square - constructor\n";
}



Square::~Square() {
  std::cout << "Square - destructor\n";
}


void Square::calculate() {
  // square functionality comes here
  if(phase < 0.5) {
    sample = 1.0;
  } else {
    sample = -1.0;
  }
  sample *= amp;
}

