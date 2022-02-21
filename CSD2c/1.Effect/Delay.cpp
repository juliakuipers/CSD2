#include "Delay.h"

Delay::Delay(float freq, float samplerate) : Effect(freq,samplerate), size(samplerate*5), numSamplesDelay(samplerate)
{
  std::cout << "Delay - Constructor " << std::endl;
  circ = new CircularBuffer(size,numSamplesDelay);
}

Delay::~Delay()
{
  delete circ;
  circ = nullptr;
}

float Delay::calculate(float sample)
{
  circ->write(sample);
  return circ->read();
}

void Delay::setDelayTime()
{
  float msDelay;
  float calc;
  while(1){
    std::cout << "set delay time " << std::endl;
    std::cin >> msDelay;
    calc = size/5000;
    if(std::cin.fail() || msDelay > 5000 || msDelay < 0 )
    {
      std::cin.clear();
      std::cout << " wrong input " << std::endl;
    }
    if(!std::cin.fail())
    {
      break;
    }
  }
  numSamplesDelay = calc * msDelay;
  std::cout << "Delay - setDelayTime - numSamplesDelay = " << numSamplesDelay << std::endl;
  circ->setReadIndex(numSamplesDelay);
  //source https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
}
