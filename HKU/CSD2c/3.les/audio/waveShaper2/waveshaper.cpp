#include "waveshaper.h"

Waveshaper::Waveshaper() : bufSize(512)
{
  std::cout << "Waveshaper - constructor \n";
  buffer = new float [bufSize];
  wtf = new WriteToFile("output.csv",true);
  setCurve(4);
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
  std::cout << "Waveshaper::setCurve - buffer[0] = " << buffer[0] << std::endl;
}

float Waveshaper::calculate(float sample)
{
  // interpolation(x,x1,x2,y1,y2);
  // sample should be scaled to the bufSize
  // i is equal to the place in the buffer
  // interpolation(scaledSample,i,i+1,buffer[i],buffer[i+1])
  sample += 1;
  float x = scale(sample,-1,1,0,bufSize);
  unsigned int intX = (int) x;
  std::cout << "Waveshaper::calculate - buffer[511] = " << buffer[511] << std::endl;
  std::cout << "Waveshaper::calculate - intX = " << intX << std::endl;
  std::cout << "Waveshaper::calculate - buffer[intX]= " << buffer[intX] << std::endl;
  interpolation(x,intX,intX+1,buffer[intX],buffer[intX+1]);
  return sample;
}

float Waveshaper::scale(float y, float x1From, float x2From, float x1To, float x2To)
{
  float yScaled = y/x2From;
  float newBufSize = x2To - x1To;
  float scale = (yScaled * newBufSize) + x1To;
  // std::cout << "Waveshaper::scale - scale = " << scale << std::endl;
  return scale;
}

float Waveshaper::interpolation(float x, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * (x-x1) / (x2-x1);
  std::cout << "Waveshaper::interpolation - x = " << x << std::endl;
  std::cout << "Waveshaper::interpolation - x1 = " <<x1 << std::endl;
  std::cout << "Waveshaper::interpolation - x2 = " << x2 << std::endl;
  std::cout << "Waveshaper::interpolation - y1 = " << y1 << std::endl;
  std::cout << "Waveshaper::interpolation - y2 = " << y2 << std::endl;
  std::cout << "Waveshaper::interpolation - y = " << y << std::endl;
  return 0;
}

// y1 and y2 are the low and the high value
// x1 and x2 are the i value and the i + 1 value from the buffer
// x is the .x value inbetween x1 and x2
// y is the output
