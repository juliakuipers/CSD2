#pragma once
#include <iostream>
#include "AudioFile.h"

class MIR
{
public:

  MIR();
  ~MIR();

  float playWAV();

private:
  void audioBuffer();
  float* buffer = nullptr;
  int numSamples;

};
