#include "synth.h"
#include <iostream>

Synth::Synth(double samplerate) : sample(0){
    std::cout << "Synth - constructor \n";
}

Synth::~Synth(){
    std::cout << "Synth - destructor \n"
}

double Synth::getSample(){
    return sample;
}

#endif
