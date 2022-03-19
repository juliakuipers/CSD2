#include <iostream>
#include "AudioFile.h"
#include "Effect.h"

class PickSample : public Effect
{
public:
  PickSample(float freq, float samplerate);
  ~PickSample();

  void changeSample();
  void resizeBuffer();
  float calculateM(float sample) override;
  float calculateR(float sample) override;
  float calculateL(float sample) override;

protected:


private:
  int numSamples = 0;
  float* buffer = nullptr;
  int bufSize = 0;
  void fillBuffer();
  float scale(float sample, float x1From, float x2From, float x1To, float x2To);
  float interpolate(float sample, float x1, float x2, float y1, float y2);


};
