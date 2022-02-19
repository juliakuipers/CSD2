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
  void setDelayTime();

protected:
  float size;
  float numSamplesDelay;

private:
  CircularBuffer* circ = nullptr;
  float msDelay;
  float samplerate;
  float delaySample;

};
