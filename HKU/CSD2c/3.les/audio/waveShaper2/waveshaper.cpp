#include "waveshaper.h"

Waveshaper::Waveshaper(float freq, float samplerate) : bufSize(512)
{
  std::cout << "Waveshaper - constructor \n";
  buffer = new float [bufSize];
  setCurve(10);
  wtf = new WriteToFile("output.csv", true);
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
    float y = interpolation(i,0,bufSize,-1.0,1.0);
    wtf->write(std::to_string(normalize * atan(k*y)) + "\n");
    buffer[i] = normalize * atan(k*y);
  }
}

float Waveshaper::calculateM(float sample)
{
  // interpolation(x,x1,x2,y1,y2);
  // interpolation(scaledSample,i,i+1,buffer[i],buffer[i+1])
  std::cout << "Waveshaper::calculate - sample = " << sample << std::endl;
  float x = scale(sample,-1,1,0,bufSize);
  //buffer[x] should be the same number
  //scaling is going wrong i think
  sample += 1;
  unsigned int intX = (int) x;
  float s = scale(x,intX,intX+1,buffer[intX],buffer[intX+1]);
  // float s = interpolation(x,intX,intX+1,buffer[intX],buffer[intX+1]);
  // float y = scale(s,0,2,-1,1);
  // std::cout << "Waveshaper::calculate - y = " << y << std::endl;
  return s;
}

float Waveshaper::scale(float y, float x1From, float x2From, float x1To, float x2To)
{
  // float delta = x2From - x1From;
  std::cout << "Waveshaper::scale - y = " << y << std::endl;
  // std::cout << "Waveshaper::scale - delta = " << delta << std::endl;
  //delta finds the value that y needs to be scaled from
  float yScaled = y/x2From;
  std::cout << "Waveshaper::scale - yScaled = " << yScaled << std::endl;
  //scales y
  float newBufSize = x2To - x1To;
  std::cout << "Waveshaper::scale - newBufSize = " << newBufSize << std::endl;
  float scale = (yScaled * newBufSize) + x1To;
  std::cout << "Waveshaper::scale - scale = " << scale << std::endl;
  return scale;
}

float Waveshaper::interpolation(float x, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((x-x1) / (x2-x1));
  float fX = x-x1;
  float newX = x2-x1;
  float yDistance = y2 - y1;
  float devideX = fX/newX;
  float multiply = yDistance * devideX;
  float sample = y1 + multiply;
  std::cout << "Waveshaper::interpolation - sample = " << sample << std::endl;
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
