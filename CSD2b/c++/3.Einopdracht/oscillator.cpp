#include "oscillator.h"

Oscillator::Oscillator() : amp(0.1),freq(440){
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::setFreq(double freq){
    this -> freq = freq;
}

void Oscillator::setAmp(double amp){
    this -> amp = amp;
}

double Oscillator::getFreq(){
    return freq;
}

double Oscillator::getAmp(){
    return amp;
}