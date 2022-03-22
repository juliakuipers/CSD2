#include <iostream>
#include "AudioFile.h"
// #include "Effect.h"
#include "writeToFile.h"
#include <algorithm>
#include <vector>
using namespace std;
#include <iterator>

class PickSample //: public Effect
{
public:
  PickSample(float freq, float samplerate);
  ~PickSample();

  void changeSample();
  void resizeBuffer();
  float calculateM(float sample);
  float calculateR(float sample);
  float calculateL(float sample);

protected:


private:
  vector<float> v;
  vector<float> averageNumber;
  //need to round the floating point numbers in order for this to work
  float floatCount = -1.0;
  void sampleAverage();
  int numSamples = 0;
  float* buffer = nullptr;
  int vectorSize;
  int bufSize = 0;
  void fillBuffer();
  float scale(float sample, float x1From, float x2From, float x1To, float x2To);
  float interpolate(float sample, float x1, float x2, float y1, float y2);
  WriteToFile* wtf = nullptr;

};
