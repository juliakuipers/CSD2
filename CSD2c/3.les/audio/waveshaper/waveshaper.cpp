#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper() : bufSize(512.0f)
{
  std::cout << "Waveshaper - constructor \n";
  buffer = new float [bufSize];
  std::cout << "Waveshaper - constructor - buffer" << buffer << std::endl;
}

Waveshaper::~Waveshaper() {}

void Waveshaper::fillBuffer()
{
  for(int i = 0 ; i<bufSize ; i++)
  {
    //sigmoid function
    buffer[i] = i;
    std::cout << "Waveshaper::fillBuffer - buffer[i] = " << buffer[i] << std::endl;
    //scale to buffer so buffer is 512 and the sample (bv 0.83) gets scaled to the buffer
    //
  }
}

float Waveshaper::calculateM(float sample)
{
  float x = sample + 1;
  interpolation(x);
  return sample;
}

void Waveshaper::interpolation(float x)
{

}

//first make the interpolation
//make a buffer which has just some numbers in it
//then thee arctan sigmoid function
