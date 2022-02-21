#pragma once
#include <iostream>
// #include<limits>
#include "oscillator.h"

class Tremolo
{
public:
  Tremolo(float freq, float samplerate);
  ~Tremolo();

  float calculate(float sample);
  void setModFreq();

private:
  Oscillator* osc = nullptr;
  float modSig;

};
