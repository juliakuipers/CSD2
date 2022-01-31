#include "sine.h"
#include "math.h"

Sine::Sine(double samplerate,double freq,double amp,double phase) : Oscillator(samplerate,freq,amp), sample(0){
    this -> samplerate = samplerate;
    this -> freq = freq;
    this -> amp = amp;
    this -> phase = phase;
    std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

void Sine::calculate() {
    //TODO both freq and phase do not get through from oscillator to sine 
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    sample = sin(M_PI * 2 * phase) * amp;
    std::cout << "phase " << phase << std::endl;
}

double Sine::getSample(){
    std::cout << ":) " << std::endl;
    return sample;
}