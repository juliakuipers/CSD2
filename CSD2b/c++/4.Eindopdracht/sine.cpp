#include "sine.h"
#include "math.h"

Sine::Sine(double samplerate) : Oscillator(samplerate), sample(0){
    this -> samplerate = samplerate;
    std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    sample = sin(M_PI * 2 * phase) * amp;
    std::cout << "sample " << sample << std::endl;
}

double Sine::getSample(){
    std::cout << ":) " << std::endl;
    return sample;
}