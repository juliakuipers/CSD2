#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper() : bufSize(512.0f)
{
  // std::cout << "Waveshaper - constructor \n";
  wtf = new WriteToFile("output.csv", true);
  buffer = new float [bufSize];
  setCurve(5);
}

Waveshaper::~Waveshaper()
{
  delete wtf;
  wtf = nullptr;
}

void Waveshaper::setCurve(float k)
{
  float normalize = 1 / atan(k);
  // std::cout<< "Waveshaper::setCurve - normalize = " << normalize << std::endl;
  for(int i = 0 ; i<bufSize ; i++)
  {
    float sigmoid = interpolation(i,bufSize,0);
    //sigmoid function
    buffer[i] = normalize * atan(k*sigmoid);
    wtf->write(std::to_string(normalize * atan(k*sigmoid)) + "\n");
    //scale to buffer so buffer is 512 and the sample (bv 0.83) gets scaled to the buffer
    //
  }
}

float Waveshaper::calculateM(float sample)
{
  float f = (sample + 1) / 2 * bufSize;
  std::cout<< "Waveshaper::calculateM - f = " << f << std::endl;
  //the incoming sample should be scaled i think
  //from [-1,1] to [0,512]
  //then it should be interpolated
  int intF = (int) f;
  std::cout<< "Waveshaper::calculateM - intF = " << intF << std::endl;
  std::cout<< "Waveshaper::calculateM - buffer[intF](low) + buffer[intF+1](high) = " << buffer[intF] << " + " << buffer[intF+1] << std::endl;
  float x = f - intF;
  std::cout<< "Waveshaper::calculateM - x = " << x << std::endl;
  //[0,2] to [0,512]

  return 0;
}

float Waveshaper::interpolation(float x, float high, float low)
{
  float scale = x / high;
  std::cout<< "Waveshaper::interpolation - scale = " << scale << std::endl;
  float interpolate = (scale*2) + -1;
  std::cout<< "Waveshaper::interpolation - interpolate = " << interpolate << std::endl;
  return interpolate;
}



//first make the interpolation
//make a buffer which has just some numbers in it
//then the arctan sigmoid function
