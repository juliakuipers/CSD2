#include "chorus.h"
#include "sine.h"

Chorus::Chorus(float freq, float samplerate) : Effect(freq,samplerate)
{
  std::cout << "Chorus - Constructor \n";
  osc1 = new Sine(4,samplerate);
  osc2 = new Sine(8,samplerate);
  circ1 = new CircularBuffer(80,8);
  circ2 = new CircularBuffer(80,3);
}

Chorus::~Chorus()
{
  std::cout << "Chorus - Destructor \n";
  delete osc1;
  delete osc2;
  delete circ1;
  delete circ2;
  osc1 = nullptr;
  osc2 = nullptr;
  circ1 = nullptr;
  circ2 = nullptr;
}

float Chorus::calculate(float sample)
{
  circ1->write(sample*(osc1->getSample()*0.5));
  circ2->write(sample*(osc2->getSample()*0.5));
  sample1 = circ1->read();
  sample2 = circ2->read();
  osc1->genNextSample();
  osc2->genNextSample();
  return sample + sample1 + sample2;
}



//buffer for chorus can be a lot smaller than the delay buffer
//might need 2 circularbuffers
//one dry signal one or two delayed signals
