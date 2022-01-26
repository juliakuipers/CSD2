//call sine in here 
//can set frequency in sine because i #include oscillator in sine (i think)
#include "synth.h"
#include <iostream>

Synth::Synth(double samplerate) {
    this->samplerate = samplerate;
    std::cout << "Synth - constructor \n";
    sine = new Sine(samplerate);
    //saw = new Saw(samplerate);
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
    delete sine;
    //delete saw;
    sine = nullptr; 
    //saw = nullptr; 
}

void Synth::set(){
    sine->setFreq(440);
    sine->setAmp(0.5);
    //saw->setFreq(20);
}

// void Synth::get(){
    // return sine->getFreq();
// }

void Synth::waveForm(){
    // std::cout << "input sine \n";
    // std::string waveForm;
    // std::cin >> waveForm;
    // if (waveForm == "Sine") {
        //osc = new Sine(samplerate);
}



void Synth::calculate(){
    sine->calculate();
}

double Synth::getSample(){
    return sine->getSample();
}