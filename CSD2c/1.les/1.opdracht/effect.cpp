#include "effect.h"

Effect::Effect(float freq, float samplerate){}

Effect::~Effect(){}

float Effect::getSample(float sample)
{
  if(onoff == 1) return calculate(sample*drywet) + sample*(1-drywet);
  else return sample;
}

void Effect::setDryWet()
{
  while (drywet > 100)
  {
    std::cout << "set drywet (0/100) \n";
    std::cin >> drywet;
  }
  drywet /= 100;
}

int Effect::bypass()
{
  onoff *= -1;
  return onoff;
}

void Effect::setFeedback()
{
  while (feedback > 100)
  {
    std::cout << "set feedback (0/100) \n";
    std::cin >> feedback;
  }
   feedback /= 100;
}
