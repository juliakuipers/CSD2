#include "effect.h"

Effect::Effect(float freq, float samplerate) { }

Effect::~Effect(){}



// float Effect::calcDryWet(float drywet){
    // return sample*=drywet;
// }

//drywet might be something i can put when i return the sample

float Effect::getSample(float sample){
    // osc->getSample() * (1-drywet);
    // std::cout << "effect - getSample \n";
    return calculate(sample*drywet) + sample*(1-drywet);
}

void Effect::setDryWet()
{
  while (drywet > 100)
  {
    std::cout << "select drywet (0/100) \n";
    std::cin >> drywet;
  }
  drywet /= 100;
}

//effect should return the sample
//so it needs the virtual function of calculate from tremolo
