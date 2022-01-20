#include "synth.h"
#include <iostream>

Synth::Synth(double samplerate){
    std::cout << "Synth - constructor \n";
    std::cout << samplerate << std::endl;
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n";
}

