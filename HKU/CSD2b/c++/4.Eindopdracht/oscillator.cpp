#include "oscillator.h"

Oscillator::Oscillator(double samplerate) : phase(0),amp(1.0),sample(0), freq(0) {
    this -> samplerate = samplerate;
    std::cout << "Oscillator - constructor \n";
    // std::cout << "Oscillator - constructor phase " << phase << std::endl;
    // std::cout << "Oscillator - constructor sample " << sample << std::endl;
    //std::cout << "Oscillator - constructor amp " << amp << std::endl;
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

//i can make a function in a derived class which is a virtual function in a base class and call the function in the base class

void Oscillator::setFreq(double freq){
    this -> freq = freq;
    std::cout << "Oscillator - setFreq freq " << freq << std::endl;
}

void Oscillator::setAmp(double amp){
    this -> amp = amp;
}

double Oscillator::getSample(){
    return sample;
    //std::cout<<"Oscillator - getSample " << sample << std::endl;
}

void Oscillator::tick(){
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    calculate();
}
