#include "sine.h"

Sine::Sine(double samplerate) : Oscillator(samplerate){
    std::cout << "Sine - Constructor \n";
}

Sine::~Sine(){
    std::cout << "Sine - Destructor \n";
}

void Sine::calculate(){
    sample = sin(M_PI * 2 * phase) * amp;
    std::cout << "Sine - Calculate \n";
}

double Sine::getSample(){
    std::cout << "Sine - getSample \n";
    return sample;
}