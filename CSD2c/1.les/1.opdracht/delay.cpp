#include "delay.h"

Delay::Delay(float freq, float samplerate) : Effect(freq,samplerate), size(samplerate*5), numSamplesDelay(samplerate)
{
  this -> samplerate = samplerate;
  circ = new CircularBuffer(size,numSamplesDelay);
  std::cout << "Delay - Constructor \n";
  circ->setReadIndex();
  setDelayTime();
  // setDryWet();
  // setFeedback();
}

Delay::~Delay()
{
  std::cout << "Delay - Destructor \n";
  delete circ;
  circ = nullptr;

}

float Delay::calculate(float sample)
{
  circ->write(sample + (delaySample*feedback));
  delaySample = circ->read();

  return delaySample;
}

void Delay::setDelayTime()
{
  //need a calculation from time to numSamplesDelay
  std::cout << "set delay time " << std::endl;
  std::cin >> msDelay;
  float calc = size/5000;
  std::cout << "calc = " << calc << std::endl;
  numSamplesDelay = calc * msDelay;
  circ->setReadIndex();
  //40/100*50
  //
  //1ms tot 5000ms

}


//new feedback function which has the delaySample and returns to calculate

//pitchmodulation on the delayed signal
//repitch
//if i want to set the delay time in a natural way i might use an if loop so:
//if(i<numSamplesDelay; i++)
