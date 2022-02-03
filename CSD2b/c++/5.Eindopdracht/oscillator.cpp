#include "oscillator.h"

Oscillator::Oscillator(double samplerate) : amp(0.5),sample(0),phase(0){
    this->samplerate = samplerate;
    std::cout << "Oscillator - Constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - Destructor \n";
}

void Oscillator::tick(){
    std::cout << "Oscillator - tick - freq " << freq <<  "\n";
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    calculate();
}

void Oscillator::setFreq(double freq){
    this -> freq = freq;
    std::cout << "Oscillator - setFreq - freq " << freq <<  "\n";
}


double Oscillator::getSample(){
    return sample * amp;
}