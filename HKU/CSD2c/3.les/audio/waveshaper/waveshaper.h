#pragma once
#include <iostream>
#include "Effect.h"

class Waveshaper : public Effect
{
public:
  Waveshaper(float freq,float samplerate);
  ~Waveshaper();

  float calculateM(float sample) override;
  void setCurve(float k);
  float calculateR(float sample) override;
  float calculateL(float sample) override;

private:
  float* buffer = nullptr;
  int bufSize;
  float interpolation(float x, float high, float low);
  float interpolate(float sample, float high, float low);

};
