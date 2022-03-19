#include <iostream>
#include "AudioFile.h"
#include "writeToFile.h"

class PickSample
{
public:
  PickSample();
  ~PickSample();

  void changeSample();
  void resizeBuffer();
  float calculateM(float sample);

protected:


private:
  int numSamples = 0;
  float* buffer = nullptr;
  int bufSize = 0;
  void fillBuffer();
  float scale(float sample, float x1From, float x2From, float x1To, float x2To);


};
