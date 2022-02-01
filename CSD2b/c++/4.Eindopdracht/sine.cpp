#include "sine.h"
#include "math.h"
// voor de communicatie tussen osc en sine moeten bij beide dingen dingen tussen de haakjes staan 
Sine::Sine(double samplerate,double freq,double amp) : Oscillator(samplerate,freq,amp){
    std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
    //TODO both freq and phase do not get through from oscillator to sine 
    sample = sin(M_PI * 2 * phase) * amp;
}
