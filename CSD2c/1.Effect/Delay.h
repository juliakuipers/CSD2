#pragma once
#include <iostream>
#include "CircularBuffer.h"

class Delay
{
public:
  Delay(float freq,float samplerate);
  ~Delay();

  float calculate(float sample);
  void setDelayTime();

protected:
  int size;
  int numSamplesDelay;

private:
  CircularBuffer* circ = nullptr;

};
