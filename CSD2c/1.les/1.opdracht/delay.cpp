#include "delay.h"

Delay::Delay(float freq, float samplerate) : Effect(freq,samplerate), size(samplerate*5), numSamplesDelay(samplerate),feedback(0.2),drywet(1){
    CircularBuffer circ(size,numSamplesDelay);
//              size is 5* samplerate
    // this -> size = size;
    // this -> numSamplesDelay = numSamplesDelay;
    std::cout << "Constructor \n";
}

Delay::~Delay(){
    std::cout << "Destructor \n";
}

float Delay::calculate(float sample){
    circ.setReadIndex(numSamplesDelay);
    circ.write(sample);
    return circ.read() + sample; 
}


// void Delay::setFeedback(int feedback){
//     this -> feedback = feedback;
// } 

// void Delay::setDrywet(int drywet){
//     this -> drywet = drywet;
// } 

// void Delay::setNumSamplesDelay(int numSamplesDelay){
    // this -> numSamplesDelay = numSamplesDelay;
    // setReadIndex(numSamplesDelay);
// }

// void Delay::setMSecDelay(int mSec){
//     //turn mSec into samples 
//     numSamplesDelay = 
//     setReadIndex(numSamplesDelay);
//     //1 second is the samplerate * 1 
//     //size is the samplerate * 5 
// }


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