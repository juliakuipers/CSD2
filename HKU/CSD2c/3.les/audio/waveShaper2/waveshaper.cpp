#include "waveshaper.h"

Waveshaper::Waveshaper() : bufSize(512)
{
  std::cout << "Waveshaper - constructor \n";
  buffer = new float [bufSize];
  wtf = new WriteToFile("output.csv",true);
}

Waveshaper::~Waveshaper()
{
  std::cout << "Waveshaper - destructor \n";
  delete buffer;
  buffer = nullptr;
  delete wtf;
  wtf = nullptr;
}

void Waveshaper::setCurve(float k)
{
  float normalize = 1.0f / atan(k);
  for(int i = 0; i < bufSize; i++)
  {
    float y = scale(i,0,bufSize,-1.0,1.0);
    buffer[i] = normalize * atan(k*y);
    wtf->write(std::to_string(normalize * atan(k*y)) + "\n");

  }
}

float Waveshaper::calculate(float sample)
{
  return sample;
}

float Waveshaper::scale(float y, float x1From, float x2From, float x1To, float x2To)
{
  float yScaled = y/x2From;
  float newBufSize = x2To - x1To;
  float scale = (yScaled * newBufSize) + x1To;

  return scale;
}

float Waveshaper::interpolation(float yScaled, float yTo, float xTo)
{
  return 0;
}
