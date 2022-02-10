#include "delay.h"

Delay::~Delay(int size, int numSamplesDelay){
//              size is 5* samplerate
    this -> size = size;
    this -> numSamplesDelay = numSamplesDelay;
    std::cout << "Constructor \n";
}

Delay::~Delay(){
    std::cout << "Destructor \n";
}

void Delay::setFeedback(int feedback){
    this -> feedback = feedback;
} 

void Delay::setDrywet(int drywet){
    this -> drywet = drywet;
} 

void Delay::setNumSamplesDelay(int numSamplesDelay){
    this -> numSamplesDelay = numSamplesDelay;
}

//write might be a function is should call in the delay 

//same goes for read only the wrap function is maybe personal to the cirular buffer 

//instelbare feedback signaal
//met instelbare dry en wet
//instelbare delay tijd in samples
//instelbare delay tijd in (m)seconden
//delay uses only an audio signal as an input 

//maybe put the delay signal *0.5 
//feedback is the delay signal send back into the input of the delay 
//y(n) = x(n-D) + fb*y(n-D)