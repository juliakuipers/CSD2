#include "sine.h"
#include "math.h"


Sine::Sine() : Sine(0, 0)
{}

Sine::Sine(float freq, float samplerate) :
  Oscillator(freq, samplerate) {}

Sine::~Sine() {}

void Sine::calcNextSample()
{
  sample = sin(M_PI * 2 * phase);
  // TODO - move to base class
  sample *= amplitude;
}
