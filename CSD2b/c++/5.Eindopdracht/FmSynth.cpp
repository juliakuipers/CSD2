#include "FmSynth.h"

FmSynth::FmSynth(double samplerate,std::string carrier,std::string modulator){
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
        std::cout << "Saw is selected \n";
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
        std::cout << "Saw is selected \n";
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
    mod->tick();
    car->setFreq((440 * pow(2 , (midi-69)/12))*mod->getSample());
    //TODO this calculation might be wrong 
    //TODO also might something that stores the calculation for mtof 
    car->tick();
}

void FmSynth::mTof(double midi){
    this -> midi = midi;
    //TODO make the calculation for FmSynth right 
    mod->setFreq((440 * pow(2 , (midi-69)/12))*2);
}

double FmSynth::getSample(){
    return car->getSample();
}