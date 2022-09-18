#include "oscillator.h"

Oscillator::Oscillator(float freq, float samplerate) :
  freq(freq), amplitude(1.0), phase(0), sample(0),
  samplerate(samplerate)
  {
    // TODO - use setFrequency & question Mila
  }

Oscillator::~Oscillator() {}

void Oscillator::initialize(float samplerate)
{
  this->samplerate = samplerate;
}

// generates and returns the next sample
float Oscillator::genNextSample() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += freq / samplerate;

  // wrap the phase so it stays in the interval [0, 1]
  if(phase > 1) phase -= 1.0;
  // let subclasses calculate the next sample
  calcNextSample();

  // return the newly generated sample
  return sample;
}

// ---- getters and setters -----

// returns current sample
float Oscillator::getSample() {
  return sample;
}

void Oscillator::setFrequency(float freq)
{
  // TODO add check to see if parameter is valid
  this->freq = freq;
}

float Oscillator::getFrequency()
{
  return freq;
}
