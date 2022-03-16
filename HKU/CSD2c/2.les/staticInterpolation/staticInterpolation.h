#include <iostream>
#pragma once
#include "CircularBuffer.h"
#include "oscillator.h"

class StaticInterpolation
{
public:
  StaticInterpolation();
  ~StaticInterpolation();

  float nnMap(float sample);
  float linMap(float sample);
  float mapInRange(float sample, float fromLow, float fromHigh, float toLow, float toHigh);

protected:
  CircularBuffer* circ = nullptr;
  Oscillator* osc = nullptr;

};
