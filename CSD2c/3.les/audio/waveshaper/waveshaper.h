#pragma once
#include <iostream>
#include "writeToFile.h"

class Waveshaper
{
public:
  Waveshaper();
  ~Waveshaper();

  float calculateM(float sample);
  void setCurve(float k);

private:
  float* buffer = nullptr;
  int bufSize;
  float interpolation(float x);
  WriteToFile* wtf = nullptr;
  
};
