#pragma once
#include <iostream>
#include "Effect.h"
#include "oscillator.h"

class Tremolo : public Effect
{
public:
  Tremolo(float freq, float samplerate);
  ~Tremolo();

  float calculate(float sample) override;
  void setModFreq();

private:
  Oscillator* osc = nullptr;
  float modSig;

};
