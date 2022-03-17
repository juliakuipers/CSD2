#include "waveshaper.h"
#include "math.h"

Waveshaper::Waveshaper(float freq, float samplerate) : Effect(freq,samplerate), bufSize(4096)
{
  buffer = new float [bufSize];
  setCurve(1);
}

Waveshaper::~Waveshaper()
{}

void Waveshaper::setCurve(float k)
{
  float normalize = 1 / atan(k);
  // std::cout<< "Waveshaper::setCurve - normalize = " << normalize << std::endl;
  for(int i = 0 ; i<bufSize ; i++)
  {
    // float x = i / bufSize;
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
  intF = (int) f;
  //retrieve the int from the scaled sample
  float x = f - intF;
  //retrieve the .x number from the sample
  // std::cout << "Waveshaper::interpolate - buffer[intF+1] & buffer[intF] = " << buffer[intF+1] << " & " << buffer[intF] << std::endl;
  float waveshape = inter(x,buffer[intF+1],buffer[intF]);
  std::cout << "Waveshaper::interpolate - waveshape = " << waveshape << std::endl;
  return waveshape;
}

float Waveshaper::interpolation(float x, float high, float low)
{
  float scale = x / bufSize;
  float interpolate = (scale*2) + -1;
  // std::cout<< "Waveshaper::interpolation - interpolate = " << interpolate << std::endl;
  return inter(interpolate,1,-1);
}

float Waveshaper::inter(float sample, float high, float low)
{
  // std::cout << "Waveshaper::interpolate - high & low = " << high << " & " << low << std::endl;
  float delta = high-low;
  // std::cout << "Waveshaper::interpolate - delta = " << delta << std::endl;
  // std::cout << "Waveshaper::interpolate - (sample * delta) + low = " << (sample * delta) + low << std::endl;
  return (sample * delta) + low;
  // return (high + ((low - high) * ((sample-intF) / ((intF+1)-intF))));
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
