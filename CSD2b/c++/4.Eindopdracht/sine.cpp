#include "sine.h"
#include "math.h"
// voor de communicatie tussen osc en sine moeten bij beide dingen dingen tussen de haakjes staan 
Sine::Sine(double samplerate) : Oscillator(samplerate){
    std::cout << "Sine - constructor\n";
    //std::cout<< "Sine - constructor sample " << sample << std::endl;
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
    //std::cout<< "Sine - calculate sample " << sample << std::endl;
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    sample = sin(M_PI * 2 * phase) * amp;
}
