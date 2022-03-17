#pragma once
#include <iostream>
#include "Effect.h"

class Waveshaper : public Effect
{
public:
  Waveshaper(float freq,float samplerate);
  ~Waveshaper();
  void setCurve(float k);

protected:
  float calculateM(float sample) override;
  float calculateR(float sample) override;
  float calculateL(float sample) override;

private:
  float* buffer = nullptr;
  int bufSize;
  float interpolation(float x, float high, float low);
  float interpolate(float sample, float high, float low);
  int intF;

};
