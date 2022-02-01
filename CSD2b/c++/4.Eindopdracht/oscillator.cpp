#include "oscillator.h"

Oscillator::Oscillator(double samplerate,double freq,double amp) : phase(0){
    this -> samplerate = samplerate;
    std::cout << "Oscillator - constructor \n";
}

Oscillator::~Oscillator(){
    std::cout << "Oscillator - destructor \n";
}

void Oscillator::nextSample(){
    phase += freq / samplerate;
    if (phase > 1) phase -= 1.0; 
    std::cout << "freq  " << freq << std::endl;
    calculate();
    //omdat calculate virtual is in oscillator en sine een derived class is met die functie kan ik calculate aanroepen in Oscillator

} 

void Oscillator::setFreq(double freq){
    this -> freq = freq;
    std::cout <<  "freq Oscillator " << freq << std::endl;
}

void Oscillator::setAmp(double amp){
    this -> amp = amp;
    std::cout << "amp " << amp << std::endl;
}

double Oscillator::getSample(){
    return sample;
}

