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
  float samplesDelay = (samplerate/msDelay) * msDelay;
  //40/100*50
  //
  //1ms tot 5000ms

  std::cout << "samplerate = " << samplerate << std::endl;
  std::cout << "samplesDelay = " << samplesDelay << std::endl;
  //1000ms = 1 sec, size = 5sec
  //size = 5000ms
  //maxMsDelay = size to ms
  //size = samplerate * 5, samplerate = 1 ms  
  //float calc = samplesDelay/maxMsDelay
  //numSamplesDelay = calc * size
  //size = 220500, 500ms = 110250
  //scale 5000ms to size 0.0 to 1
  //(samplerate/500)*samplerate


}


//new feedback function which has the delaySample and returns to calculate

//pitchmodulation on the delayed signal
//repitch
//if i want to set the delay time in a natural way i might use an if loop so:
//if(i<numSamplesDelay; i++)
