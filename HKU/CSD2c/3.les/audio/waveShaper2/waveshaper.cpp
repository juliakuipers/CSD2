#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float freq, float samplerate) : Effect(freq,samplerate), bufSize(512)
{
  std::cout << "Waveshaper - constructor \n";
  buffer = new float [bufSize];
  setCurve(20);
}

Waveshaper::~Waveshaper()
{
  std::cout << "Waveshaper - destructor \n";
  delete buffer;
  buffer = nullptr;
}

void Waveshaper::setCurve(float k)
{
  float normalize = 1.0f / atan(k);
  for(int i = 0; i < bufSize; i++)
  {
    float y = interpolation(i,0,bufSize,-1,1);
    // wtf->write(std::to_string(normalize * atan(k*y)) + "\n");
    buffer[i] = normalize * atan(k*y);
  }
}

float Waveshaper::calculateM(float sample)
{
  sample += 1.0;
  float x = scale(sample,0,2.1,0,bufSize);
  unsigned int intX = (int) x;
  float s = interpolation(x,intX,intX+1,buffer[intX],buffer[intX+1]);
  return s;
}

float Waveshaper::scale(float y, float x1From, float x2From, float x1To, float x2To)
{
  float delta = x2From - x1From;
  float yScaled = y/delta;
  std::cout << yScaled << std::endl;
  float newBufSize = x2To - x1To;
  float scale = (yScaled * newBufSize) + x1To;
  return scale;
}

float Waveshaper::interpolation(float x, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((x-x1) / (x2-x1));
  // interpolation(scaledSample,i,i+1,buffer[i],buffer[i+1])
  std::cout << "Waveshaper::interpolation - x = " << x << std::endl;
  std::cout << "Waveshaper::interpolation - x1 = " <<x1 << std::endl;
  std::cout << "Waveshaper::interpolation - x2 = " << x2 << std::endl;
  std::cout << "Waveshaper::interpolation - y1 = " << y1 << std::endl;
  std::cout << "Waveshaper::interpolation - y2 = " << y2 << std::endl;
  std::cout << "Waveshaper::interpolation - y = " << y << std::endl;
  return y;
}

float Waveshaper::calculateL(float sample)
{
  return 0;
}

float Waveshaper::calculateR(float sample)
{
  return 0;
}

// y1 and y2 are the low and the high value
// x1 and x2 are the i value and the i + 1 value from the buffer
// x is the .x value inbetween x1 and x2
// y is the output
