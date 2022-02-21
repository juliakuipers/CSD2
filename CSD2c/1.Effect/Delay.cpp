#include "Delay.h"

Delay::Delay(float freq, float samplerate) : size(samplerate*5), numSamplesDelay(samplerate)
{
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
    if(std::cin.fail()) std::cin.clear();
    if(!std::cin.fail()) break;
  }
  numSamplesDelay = calc * msDelay;
  std::cout << "Delay - setDelayTime - numSamplesDelay = " << numSamplesDelay << std::endl;
  circ->setReadIndex(numSamplesDelay);
  //source https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
}
