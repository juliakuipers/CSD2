#include "FmSynth.h"

FmSynth::FmSynth(double samplerate,std::string carrier,std::string modulator){
    this -> samplerate = samplerate;
    this -> carrier = carrier;
    this -> modulator = modulator;
    

    std::cout << "FmSynth - Constructor \n";
}
