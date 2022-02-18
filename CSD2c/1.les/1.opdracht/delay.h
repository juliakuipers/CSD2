#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include "effect.h"

class Delay : public Effect
{
public:
  Delay(float freq, float samplerate);
  ~Delay();

  float calculate(float sample) override;

protected:
  int size;
  int numSamplesDelay;

private:
  CircularBuffer* circ = nullptr;
  float delaySample = 0;

};
