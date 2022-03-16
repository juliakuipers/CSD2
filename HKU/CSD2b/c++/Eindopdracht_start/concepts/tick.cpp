#include <iostream>
#include "math.h"

class Square{
    public:

        Square();
        ~Square();

        void tick();
    private:
        float frequency;
        float amplitude;
        float phase;
        // sample contains the current sample
        float sample;
        double samplerate;


}

Square::Square(){
    std::cout 
    << "Square Constructor \n";
}

Square::~Square(){
    std::cout 
    << "Square Destructor \n";
}

void Square::tick() {
  // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
  // NOTE 2. - still need todo 'something' with the phase, see 04_sin_function
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase) * amplitude; //phase voor square 
  if(phase > 0.5){
    sample = 1;
  }
}