#include <iostream>
#pragma once

class StaticInterpolation
{
public:
  StaticInterpolation();
  ~StaticInterpolation();

  float nnMap(float value, float low, float high);
  float linMap(float value, float low, float high);
  float mapInRange(float value, float fromLow, float fromHigh, float toLow, float toHigh);

};
