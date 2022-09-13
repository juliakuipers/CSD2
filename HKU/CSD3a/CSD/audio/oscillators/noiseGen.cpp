#include "noiseGen.h"

NoiseGen::NoiseGen(float frequency, float samplerate) :
  Oscillator(frequency, samplerate){}

NoiseGen::~NoiseGen() {}

void NoiseGen::calcNextSample()
{
  std::cout << "NoiseGen::calcNextSample()"  << '\n';
}
