#include "delay.h"

Delay::Delay(float freq, float samplerate) : Effect(freq,samplerate), size(samplerate*5), numSamplesDelay(samplerate)
{
  circ = new CircularBuffer(size,numSamplesDelay);
  std::cout << "Delay - Constructor \n";
  circ->setReadIndex();
  setFeedback();
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


//new feedback function which has the delaySample and returns to calculate

// void Delay::setFeedback()
// {
//   Effect::setFeedback();
// }

//pitchmodulation on the delayed signal
//repitch
//if i want to set the delay time in a natural way i might use an if loop so:
//if(i<numSamplesDelay; i++)
