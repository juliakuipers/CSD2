#include "delay.h"
#include "square.h"

Delay::Delay(float freq, float samplerate) : size(samplerate*5), numSamplesDelay(samplerate)
{
  CircularBuffer circ(size,numSamplesDelay);
  osc = new Square(freq,samplerate);
  std::cout << "Delay - Constructor \n";
}

Delay::~Delay()
{
  std::cout << "Delay - Destructor \n";
  delete osc;
  osc = nullptr;
}

float Delay::calculate()
{
  circ.setReadIndex();
  circ.write(osc->genNextSample());
  float sample = circ.read();
  return sample;
}
