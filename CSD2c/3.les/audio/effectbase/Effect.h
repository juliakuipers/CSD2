#pragma once
#include <iostream>

class Effect
{
public:
  Effect(float freq,float samplerate);
  ~Effect();

  virtual float calculateM(float sample) = 0;
  virtual float calculateL(float sample) = 0;
  virtual float calculateR(float sample) = 0;
  float getEffectSampleM(float sample);
  float getEffectSampleL(float sample);
  float getEffectSampleR(float sample);
  void setDryWet();
  void setFeedback();
  int bypass();

protected:
  float samplerate;
  float freq;

private:
  float drywet;
  float feedback;
  float getSample;
  int onoff;

};
