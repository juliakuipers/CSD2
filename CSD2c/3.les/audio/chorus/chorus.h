#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include "oscillator.h"
#include "Effect.h"

class Chorus : public Effect
{
public:
  Chorus(float freq, float samplerate);
  ~Chorus();

  float calculate(float sample) override;

protected:
  int size;
  int numSamplesDelay;

private:
  Oscillator* osc = nullptr;
  CircularBuffer* circ = nullptr;


};
