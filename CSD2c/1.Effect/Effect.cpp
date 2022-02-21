#include "Effect.h"

Effect::Effect(float freq, float samplerate) : drywet(0), feedback(0)
{}

Effect::~Effect()
{}

float Effect::getEffectSample(float sample)
{
  // std::cout << drywet << std::endl;
  return calculate(sample*drywet) + sample*(1-drywet);
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
  std::cout << "Effect - getEffectSample - drywet = " << drywet << std::endl;
}
