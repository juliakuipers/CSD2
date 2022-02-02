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
    std::cout << "Oscillator - Tick \n";
    std::cout << "Oscillator - freq " << freq <<"\n";
    calculate();
}