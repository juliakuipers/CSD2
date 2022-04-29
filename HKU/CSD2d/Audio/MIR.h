#pragma once
#include <iostream>
#include "AudioFile.h"

class MIR
{
public:

  MIR();
  ~MIR();

  float playRWAV();
  float playLWAV();

private:
  void audioBuffer();
  float* bufferR = nullptr;
  float* bufferL = nullptr;
  int numSamples;
  int sampleCount;

};
