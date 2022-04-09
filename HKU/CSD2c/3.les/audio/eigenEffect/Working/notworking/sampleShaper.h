#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Effect.h"
#include "AudioFile.h"

class SampleShaper : public Effect
{
public:
  SampleShaper(float freq,float samplerate);
  ~SampleShaper();

  float calculateM(float sample) override;

private:
  std::vector<float> v;
  std::vector<float> a;
  float* buffer = nullptr;

  float currentSample;
  float floatCount;
  float drywet;
  float begin;
  float end;
  float k;
  int vectorSize;
  int numSamples;
  int channel;
  std::string wav;

  void fillBuffer();
  void calcAverage();
  void pickSample();

};
