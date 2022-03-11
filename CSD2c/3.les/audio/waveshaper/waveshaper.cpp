#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper() : bufSize(512.0f)
{
  // std::cout << "Waveshaper - constructor \n";
  wtf = new WriteToFile("output.csv", true);
  buffer = new float [bufSize];
  setCurve(1);
}

Waveshaper::~Waveshaper()
{
  delete wtf;
  wtf = nullptr;
}

void Waveshaper::setCurve(float k)
{
  float normalize = 1 / atan(k);
  for(int i = 0 ; i<bufSize ; i++)
  {
    float sigmoid = interpolation(i);
    //sigmoid function
    buffer[i] = normalize * atan(k*sigmoid);
    wtf->write(std::to_string(normalize * atan(k*sigmoid)) + "\n");
    //scale to buffer so buffer is 512 and the sample (bv 0.83) gets scaled to the buffer
    //
  }
}

float Waveshaper::calculateM(float sample)
{
  for(int i = 0 ; i < bufSize ; i++){
    float f = (sample + 1) / 2 * bufSize;
    int intValue = (int) f;
    float x = f - intValue;
  //[0,2] to [0,512]
  }
  return 0;
}

float Waveshaper::interpolation(float x)
{
  float scale = x / bufSize;
  float interpolate = (scale*2) + -1;
  // std::cout<< "Waveshaper::interpolation - x = " << x << std::endl;
  return interpolate;
}


//first make the interpolation
//make a buffer which has just some numbers in it
//then the arctan sigmoid function
