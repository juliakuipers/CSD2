#pragma once
#include <iostream>

class Waveshaper
{
public:
  Waveshaper();
  ~Waveshaper();

  float calculateM(float sample);
  void interpolation(float x);

private:
  float* buffer = nullptr;
  int bufSize;
  void fillBuffer();

};
