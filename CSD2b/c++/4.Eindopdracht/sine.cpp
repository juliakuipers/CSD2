#include "sine.h"
#include "math.h"
// voor de communicatie tussen osc en sine moeten bij beide dingen dingen tussen de haakjes staan 
Sine::Sine(double samplerate,double amp) : Oscillator(samplerate,amp),sample(0){
    std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
    //TODO amp does not go through right 
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    sample = sin(M_PI * 2 * phase) * amp;
    std::cout<< "Sine - Calculate amp " << amp << std::endl;
}
