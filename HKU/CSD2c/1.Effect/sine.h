#ifndef _SINE_H_
#define _SINE_H_
#include <iostream>
#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine();
  Sine(float freq, float samplerate);
  ~Sine();

private:
  // calculate the next sample according to sine calculation
  void calcNextSample() override;
};

#endif
