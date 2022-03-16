#include <iostream>
// #include "oscillator.h"
// #include "Effect.h"

class FreqShifter
{
public:
  FreqShifter(float freq,float samplerate);
  ~FreqShifter();
  float calculate(float sample);

protected:

private:
  // oscillator* osc = nullptr;
};
