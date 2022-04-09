#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "Effect.h"
#include "AudioFile.h"
// #include "writeToFile.h"
#include "oscillator.h"

class SampleShaper : public Effect
{
public:
  SampleShaper(float freq,float samplerate);
  ~SampleShaper();

  float calculateM(float sample) override;
  float calculateR(float sample) override;
  float calculateL(float sample) override;

private:
  std::vector<float> v;
  std::vector<float> a;
  float* buffer = nullptr; //should be dynamically allocated since there are two ways to fill the buffer
  // WriteToFile* writeFile = nullptr;
  Oscillator* osc;

  float currentSample;
  float floatCount;
  float drywet;
  float begin;
  float end;
  int vectorSize;
  int numSamples;
  int channel;
  std::string wav;

  void fillBuffer();
  void calcAverage(); //sampleAverage
  void allSamples();
  void pickSample();

};
