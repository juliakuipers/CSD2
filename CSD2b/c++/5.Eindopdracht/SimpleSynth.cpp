#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate) : Synth(samplerate), freq(freq){
    std::cout << "SimpleSynth - Constructor \n";
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - Destructor \n";
}

void SimpleSynth::calculate(){
    std::cout << "Calculating \n";
}

double SimpleSynth::getSample(){
    std::cout << "Returning Sample \n";
    return 0;
}

double SimpleSynth::mTof(double midi){
    this -> midi = midi;
    freq = (midi /127.0) * 20000.0;
    std::cout << "Frequency = " << freq << std::endl;
    return 0;
}