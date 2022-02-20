#include "Tremolo.h"
#include "square.h"
#include "sine.h"

Tremolo::Tremolo(float freq,float samplerate)
{
  osc = new Sine(freq,samplerate);
}

Tremolo::~Tremolo()
{}

void Tremolo::setModFreq()
{
  float setMFreq;
  std::cout << " Tremolo - setModFreq " << std::endl;
  std::cin >> setMFreq;
  osc->setFrequency(setMFreq);
  //fast medium slow 
}

float Tremolo::calculate(float sample)
{
  modSig = (osc->genNextSample() + 1.0)*0.5;
  // std::cout << "Tremolo::calculate - modSig = " << modSig << std::endl;
  return sample * modSig;
}
