#include "oscillator.h"

Oscillator::Oscillator(double samplerate) : phase(0){
    this -> samplerate = samplerate;
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::waveForm(){

} 

void Oscillator::setFreq(double freq){
    this -> freq = freq;
}

void Oscillator::calculate(){
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    std::cout << phase << std::endl; 
}

