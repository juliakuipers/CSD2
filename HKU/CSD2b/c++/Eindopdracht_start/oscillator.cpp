//so for fm i'll need another oscillator, came to the conclution to make 3 oscillators and put those in a base class synth maybe
//one oscillator for waveforms, one for fm, and another one
//can make the fm maybe with pointers by multiplying the fMod with freq and send the sample from the synth 
//first the modulating frequency gets calculated
//then the modulating frequency gets multiplied with the frequency in the waveform oscillator
//the sample gets calculated in the waveform oscillator 
//the sample gets send from the synth 
//could also make a fm synth with a carrier and modulator (would be way easier) 


#include "oscillator.h"
#include <iostream>
 //                     initialize this in main
Oscillator::Oscillator(double samplerate,double freq,double amp) : freq(freq), amp(amp),sample(0),samplerate(samplerate){
    std::cout 
    << "Oscillator Constructor"
    << std::endl;
}

Oscillator::~Oscillator(){
    std::cout
    << "Oscillator Destructor"
    << std::endl;
}

//getters and setters

float Oscillator::getSample() {
  return sample;
}

// void Oscillator::mod(double mFreq){
//   for(unsigned int i = 0; i < nframes; i++){
//       mFreq = Oscillator.getSample();
//       //outBuf[i] goes through the waveForm sample by sample and also makes it so you can hear a sound, i however dont need the sound just the waveform 
//       Oscillator.calculate();  
//       //calculates the next step 
//       return mFreq;   
//   }
//
//}
void Oscillator::setFreq(double freq)
{
  //this->freq = freq * mFreq;
  this->freq = freq;
  std::cout << "setFreq\n";
  //my guess is that nframes is samplerate 
}

void Oscillator::setAmp(double amp){
  this->amp = amp;
}

