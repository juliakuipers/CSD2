#include "oscillator.h"

Oscillator::Oscillator(double samplerate) : amp(0.5),sample(0),phase(0){
    this->samplerate = samplerate;
    std::cout << "Oscillator - Constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - Destructor \n";
}

void Oscillator::tick(){
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    calculate();
}

void Oscillator::setFreq(double freq){
    this -> freq = freq;
}


double Oscillator::getSample(){
    std::cout << "Oscillator - getSample - Sample " << sample << "\n";
    return sample;
}