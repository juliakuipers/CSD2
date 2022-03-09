#pragma once
#include <iostream>
#include "Effect.h"

class Waveshaper : public Effect
{
public:
  Waveshaper(float freq, float samplerate);
  ~Waveshaper();

  float calculateM(float sample) override;

};
