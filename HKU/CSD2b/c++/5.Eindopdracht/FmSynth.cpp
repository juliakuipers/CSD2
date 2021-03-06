#include "FmSynth.h"

FmSynth::FmSynth(double samplerate,std::string carrier,std::string modulator) : Synth(samplerate,carrier,modulator){
    this -> samplerate = samplerate;
    this -> carrier = carrier;
    this -> modulator = modulator;
    if (carrier == "Sine") {
        car = new Sine(samplerate);
        std::cout << "Sine is selected \n";
    }
    if (carrier == "Saw") {
        car = new Saw(samplerate);
        std::cout << "Saw is selected \n";
    }
    if (carrier == "Square") {
        car = new Square(samplerate);
        std::cout << "Square is selected \n";
    }    

    if (modulator == "Sine") {
        mod = new Sine(samplerate);
        std::cout << "Sine is selected \n";
    }
    if (modulator == "Saw") {
        mod = new Saw(samplerate);
        std::cout << "Saw is selected \n";
    }
    if (modulator == "Square") {
        mod = new Square(samplerate);
        std::cout << "Square is selected \n";
    } 
    std::cout << "FmSynth - Constructor \n";
}

FmSynth::~FmSynth(){
    std::cout << "FmSynth - Destructor \n";
    delete car;
    delete mod;
    car = nullptr;
    mod = nullptr;
}

void FmSynth::calculate(){
    mod->setFreq(freq*2);
    car->setFreq(freq);
    mod->tick();
    car->tick();
    car->setFreq(freq* mod->getSample());
    //TODO also might something that does the calculation for mtof and returns the frequency  
}

double FmSynth::getSample(){
    std::cout << "FmSynth - getSample - car->getSample " << car->getSample() <<  "\n";
    return car->getSample();
}

void FmSynth::mTof(double midi){
    // this -> midi = midi;
    Synth::mTof(midi);
    //can call the overwritten function mTof from synth like this 
    mod->setFreq(freq*2);
    car->setFreq(freq);

    //TODO work with a getFreq; 
}