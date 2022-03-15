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

  float calculateM(float sample) override;
  float calculateL(float sample) override;
  float calculateR(float sample) override;

protected:
  int size;
  int numSamplesDelay;

private:
  Oscillator* osc1 = nullptr;
  Oscillator* osc2 = nullptr;
  CircularBuffer* circ1 = nullptr;
  CircularBuffer* circ2 = nullptr;
  void setDelayAmt();
  float oscAmp1;
  float oscAmp2;
  float sample1;
  float sample2;

};
