#include "SimpleSynth.h"

SimpleSynth::SimpleSynth(double samplerate,std::string carrier){
    this -> samplerate = samplerate;
    this -> carrier = carrier;
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
    std::cout << "SimpleSynth - Constructor \n";
}

SimpleSynth::~SimpleSynth(){
    std::cout << "SimpleSynth - Destructor \n";
    delete car;
    car = nullptr;
}

void SimpleSynth::calculate(){
    car->tick();
    // std::cout << "SimpleSynth - calcate - osc->tick() " << osc->tick() << "\n";

}

double SimpleSynth::getSample(){
    return car->getSample();
}

void SimpleSynth::mTof(double midi){
    this -> midi = midi;
    //std::cout << "SimpleSynth - mTof - midi " << midi <<  "\n";
    car->setFreq(440 * pow(2 , (midi-69)/12));
}