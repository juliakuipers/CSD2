#include "oscillator.h"
#include <iostream>

class NoiseGen : public Oscillator
{
public:
  NoiseGen(float frequency, float samplerate);
  ~NoiseGen();

private:
  void calcNextSample() override;
};
