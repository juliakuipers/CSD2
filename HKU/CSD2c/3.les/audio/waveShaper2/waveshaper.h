#include <iostream>
#include "math.h"
#include "writeToFile.h"
// #include "Effect.h"

class Waveshaper
{
public:
  Waveshaper(float freq,float samplerate);
  ~Waveshaper();

  float calculateM(float sample);
  float calculateR(float sample);
  float calculateL(float sample);
  void setCurve(float k);

protected:

private:
  float* buffer = nullptr;
  int bufSize;
  float scale(float y, float x1From, float x2From, float x1To, float x2To);
  float interpolation(float x, float x1, float x2, float y1, float y2);
  WriteToFile* wtf = nullptr;
  // y1 and y2 are the low and the high value
  // x1 and x2 are the i value and the i + 1 value from the buffer
  // x is the .x value inbetween x1 and x2
  // y is the output

};
