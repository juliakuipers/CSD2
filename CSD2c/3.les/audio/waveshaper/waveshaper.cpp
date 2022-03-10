#include "waveshaper.h"

Waveshaper::Waveshaper(float freq, float samplerate) : Effect(freq,samplerate), bufSize(512.0f)
{
  buffer = new float [bufSize];
}

Waveshaper::~Waveshaper() {}

void fillBuffer(float buffer, int bufSize)
{
  for(int i < 0 ; i < bufSize ; i++){
    
  }
}

float Waveshaper::calculateM(float sample)
{
  return sample;
}
