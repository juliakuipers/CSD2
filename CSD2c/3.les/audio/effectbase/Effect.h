#pragma once
#include <iostream>

class Effect
{
public:
  Effect(float freq,float samplerate);
  ~Effect();

  virtual float calculate(float sample) = 0;
  void setDryWet();
  void setFeedback();
  float getEffectSample(float sample);
  int bypass();

protected:
  float samplerate;
  float freq;

private:
  float drywet;
  float feedback;
  float getSample;
  int onoff = 1;

};
