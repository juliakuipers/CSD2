#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include "oscillator.h"

class Delay
{
public:
  Delay(float freq, float samplerate);
  ~Delay();

  float calculate();

protected:
  int size;
  int numSamplesDelay;

private:
  CircularBuffer circ;
  Oscillator* osc = nullptr;

};
