#include "oscillator.h"

Oscillator::Oscillator(double samplerate,double amp) : phase(0),sample(0) {
    this -> samplerate = samplerate;
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

// void Oscillator::nextSample(){
    // phase += freq / samplerate;
    // if (phase > 1) phase -= 1.0; 
    // calculate();
    // std::cout<<sample << std::endl;
    // omdat calculate virtual is in oscillator en sine een derived class is met die functie kan ik calculate aanroepen in Oscillator
// } 

void Oscillator::setFreq(double freq){
    this -> freq = freq;
}

void Oscillator::setAmp(double amp){
    this -> amp = amp;
}

double Oscillator::getSample(){
    return sample;
    //std::cout<<"Oscillator - getSample " << sample << std::endl;
}

