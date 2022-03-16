#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float freq, float samplerate) : Effect(freq,samplerate), bufSize(512)
{
  // std::cout << "Waveshaper - constructor \n";
  // wtf = new WriteToFile("output.csv", true);
  buffer = new float [bufSize];
  setCurve(7);
}

Waveshaper::~Waveshaper()
{
  // delete wtf;
  // wtf = nullptr;
}

void Waveshaper::setCurve(float k)
{
  float normalize = 1 / atan(k);
  // std::cout<< "Waveshaper::setCurve - normalize = " << normalize << std::endl;
  for(int i = 0 ; i<bufSize ; i++)
  {
    // float x = i / bufSize;
    // std::cout<< "Waveshaper::setCurve - x = " << x << std::endl;
    // std::cout<< "Waveshaper::setCurve - i = " << i << std::endl;
    // std::cout<< "Waveshaper::setCurve - bufSize = " << bufSize << std::endl;
    //scale i to buffer
    float sigmoid = interpolation(i,bufSize,0);
    buffer[i] = normalize * atan(k*sigmoid);
    //fill buffer with sigmoid function
    // wtf->write(std::to_string(normalize * atan(k*sigmoid)) + "\n");
    //scale to buffer so buffer is 512 and the sample (bv 0.83) gets scaled to the buffer
    //
  }
}

float Waveshaper::calculateM(float sample)
{
  float f = ((sample + 1) / 2) * bufSize;
  //sample = [-1,1] + 1 = [0,2] / 2 = max 1 * bufSize = scaled to buffer
  //incoming sample gets scaled from [-1,1] to [0,512]
  //scale the sample so its in [0,2] then scale it to the buffer size
  int intF = (int) f;
  //retrieve the int from the scaled sample
  float x = f - intF;
  //retrieve the .x number from the sample
  float waveshape = interpolate(x,buffer[intF+1],buffer[intF]);
  return waveshape;
}

float Waveshaper::interpolation(float x, float high, float low)
{
  float scale = x / bufSize;
  // float delta = high - low;
  // std::cout<< "Waveshaper::interpolation - delta = " << delta << std::endl;
  // std::cout<< "Waveshaper::interpolation - scale = " << scale << std::endl;
  float interpolate = (scale*2) + -1;
  // std::cout<< "Waveshaper::interpolation - interpolate = " << interpolate << std::endl;
  return interpolate;
}

float Waveshaper::interpolate(float sample, float high, float low)
{
  float delta = high-low;
  return (sample * delta) + low;
}

float Waveshaper::calculateL(float sample)
{
  return 0;
}

float Waveshaper::calculateR(float sample)
{
  return 0;
}

//first make the interpolation
//make a buffer which has just some numbers in it
//then the arctan sigmoid function
