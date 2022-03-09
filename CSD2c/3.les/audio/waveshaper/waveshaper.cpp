#include "waveshaper.h"

Waveshaper::Waveshaper(float freq, float samplerate) : Effect(freq,samplerate) {}

Waveshaper::~Waveshaper() {}

float Waveshaper::calculateM(float sample)
{
  return sample;
}
