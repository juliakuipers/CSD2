#include "Effect.h"
// #include "square.h"
// #include "sine.h"

Effect::Effect(float freq, float samplerate) : drywet(0), feedback(0)
{
  this -> freq = freq;
  this -> samplerate = samplerate;
  // osc = new Sine(freq,samplerate);
}

Effect::~Effect()
{}

float Effect::getEffectSample(float sample)
{
  // std::cout << drywet << std::endl;
  if(onoff == 1) return calculate(sample*drywet) + sample*(1-drywet);
  else return sample;
}

void Effect::setDryWet()
{
  while(1)
  {
    std::cout << " Effect setDrywet (0/100) " << std::endl;
    std::cin>> drywet;
    if (std::cin.fail() || drywet > 100 || drywet < 0)
    {
      std::cin.clear();
    }
    if(!std::cin.fail())
    {
      break;
    }
  }
  drywet /= 100;
}

int Effect::bypass()
{
  onoff *= -1;
  return onoff;
}
