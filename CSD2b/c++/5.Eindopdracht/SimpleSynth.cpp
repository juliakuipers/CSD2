#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate,std::string carrier){
    this -> samplerate = samplerate;
    this -> carrier = carrier;
    if (carrier == "Sine") {
        osc = new Sine(samplerate);
        std::cout << "Sine is selected \n";
    }
    if (carrier == "Saw") {
        osc = new Saw(samplerate);
        std::cout << "Saw is selected \n";
    }
    if (carrier == "Square") {
        osc = new Square(samplerate);
        std::cout << "Saw is selected \n";
    }
    std::cout << "SimpleSynth - Constructor \n";
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - Destructor \n";
    delete osc;
    osc = nullptr;
}

void SimpleSynth::calculate(){
    osc->tick();
    // std::cout << "SimpleSynth - calcate - osc->tick() " << osc->tick() << "\n";

}

double SimpleSynth::getSample(){
    return osc->getSample();
}

void SimpleSynth::mTof(double midi){
    this -> midi = midi;
    //std::cout << "SimpleSynth - mTof - midi " << midi <<  "\n";
    osc->setFreq((midi /127.0) * 20000.0);
}