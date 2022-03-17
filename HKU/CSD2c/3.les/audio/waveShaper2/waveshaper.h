#include <iostream>
#include "math.h"
#include "writeToFile.h"

class Waveshaper
{
public:
  Waveshaper();
  ~Waveshaper();

  float calculate(float sample);
  void setCurve(float k);

protected:

private:
  float* buffer = nullptr;
  int bufSize;
  float scale(float y, float x1From, float x2From, float x1To, float x2To);
  float interpolation(float yScaled, float yTo, float xTo);
  WriteToFile* wtf = nullptr;
  // y1 and y2 are the low and the high value
  // x1 and x2 are the i value and the i + 1 value from the buffer
  // x is the .x value inbetween x1 and x2
  // y is the output

};
