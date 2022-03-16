//calculation 
//modulator caculation (without any audio signal)
//modulator * frequency + fundemental frequency 
//both modulator and carrier are oscillators
//maybe make a function fm in oscillator where the modulator gets calculated, so i can implement it on every waveform in the oscillator. then freq += fundemental * modulator   
//oscillator has an fm function (serum)  
//something with ratio
#include "fm.h"
#include <iostream>

Fm::Fm(double samplerate, double freq) : Oscillator(samplerate,freq){
    std::cout
    << "Fm - constructor"
    << std::endl;
}

Fm::~Fm(){
    std::cout
    << "Fm - destructor"
    << std::endl;    
}


void Fm::mod(double mFreq){
  for(unsigned int i = 0; i < nframes; i++){
      mFreq = Fm.getSample();
      //outBuf[i] goes through the waveForm sample by sample and also makes it so you can hear a sound, i however dont need the sound just the waveform 
      Fm.calculate();  
      //calculates the next step  
      return mFreq;  
  }
  
}