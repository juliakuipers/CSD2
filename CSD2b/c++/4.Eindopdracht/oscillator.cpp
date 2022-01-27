#include "oscillator.h"

Oscillator::Oscillator() : Synth(samplerate,midi,amp), phase(0){
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::waveForm(){

} 

void Oscillator::calculate(){
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    std::cout << phase << std::endl; 
}