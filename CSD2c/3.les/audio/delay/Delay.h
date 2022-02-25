#pragma once
#include <iostream>
#include "CircularBuffer.h"
#include "Effect.h"

class Delay : public Effect
{
public:
  Delay(float freq,float samplerate);
  ~Delay();

  float calculate(float sample) override;
  void setDelayTime();

protected:
  int size;
  int numSamplesDelay;

private:
  CircularBuffer* circ = nullptr;

};
