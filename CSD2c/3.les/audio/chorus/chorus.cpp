#include "chorus.h"
#include "sine.h"

Chorus::Chorus(float freq, float samplerate) : Effect(freq,samplerate)
{
  std::cout << "Chorus - Constructor \n";
  osc = new Sine(440,44100);
  circ = new CircularBuffer(4,2);
}

Chorus::~Chorus()
{
  std::cout << "Chorus - Destructor \n";
  delete osc;
  delete circ;
  osc = nullptr;
  circ = nullptr;
}

float Chorus::calculate(float sample)
{
  return sample;
}

//buffer for chorus can be a lot smaller than the delay buffer
//might need 2 circularbuffers
//one dry signal one or two delayed signals
