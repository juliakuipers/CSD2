//call sine in here 
//can set frequency in sine because i #include oscillator in sine (i think)
#include "synth.h"
#include <iostream>

Synth::Synth(double samplerate) : Sine(samplerate),samplerate(samplerate){
    std::cout << "Synth - constructor \n";
    osc = new Sine(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    delete osc;
    osc = nullptr;  
}

void Synth::set(){
    osc->setFreq(440);
    osc->setAmp(0.5);
}

void Synth::waveForm(){
    // std::cout << "input sine \n";
    // std::string waveForm;
    // std::cin >> waveForm;
    // if (waveForm == "Sine") {
        //osc = new Sine(samplerate);
}



void Synth::calculate(){
    osc->calculate();
}

double Synth::getSample(){
    return osc->getSample(); 
}