#pragma once
#include <iostream>
#include "Effect.h"
#include "oscillator.h"

class Tremolo : public Effect
{
public:
  Tremolo(float freq, float samplerate);
  ~Tremolo();

  float calculateM(float sample) override;
  void setModFreq();
  float calculateR(float sample) override;
  float calculateL(float sample) override;

private:
  Oscillator* osc = nullptr;
  float modSig;

};
