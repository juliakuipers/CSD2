#include "pickSample.h"
AudioFile<float> audioFile;

PickSample::PickSample(float freq, float samplerate) : Effect(freq,samplerate)
{
  std::cout << "PickSample::Constructor " << std::endl;
  audioFile.load ("../3.les/audio/eigenEffect/samples/OH.wav");
  audioFile.setAudioBufferSize (1, 512);
  fillBuffer();
  numSamples = 512;
  std::cout << "PickSample::Constructor - numSamples = " << numSamples <<std::endl;
  bufSize = numSamples;
  audioFile.printSummary();
  buffer = new float[bufSize];
}

PickSample::~PickSample()
{
  std::cout << "PickSample::Destructor " << std::endl;
}

float PickSample::calculateM(float sample)
{
  // std::cout << "PickSample::calculateM - sample =  = " << sample << std::endl;
  sample += 1;
  // std::cout << "PickSample::calculateM - sample +=1 =  = " << sample << std::endl;
  // std::cout << "PickSample::calculateM - numSamples =  = " << numSamples << std::endl;
  float s = scale(sample,0,2,0,numSamples);
  // std::cout << "PickSample::calculateM - s =  = " << s << std::endl;
  int intS = (int) s;
  // std::cout << "PickSample::calculateM - intS =  = " << intS << std::endl;
  float y = interpolate(s,intS,intS+1,buffer[intS],buffer[intS+1]);
  // std::cout << "PickSample::calculateM - buffer[intS] and buffer[intS+1] = " << buffer[intS] << " and " << buffer[intS+1] << std::endl;
  // std::cout << "PickSample::calculateM - y =  = " << y << std::endl;
  return y;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  float xFromDistance = x2From - x1From;
  // std::cout << "PickSample::scale - xFromDistance = " << xFromDistance << std::endl;
  float sampleScaled = sample/xFromDistance;
  // std::cout << "PickSample::scale - sampleScaled = " << sampleScaled << std::endl;
  // std::cout << "PickSample::scale - x1To = " << x1To << std::endl;
  // std::cout << "PickSample::scale - x2To = " << x2To << std::endl;
  float xToDistance = x2To - x1To;
  // std::cout << "PickSample::scale - xToDistance = " << xToDistance << std::endl;
  float x = (sampleScaled * xToDistance) + x1To;
  // std::cout << "PickSample::scale - x = " << x << std::endl;
  return x;
}

float PickSample::interpolate(float sample, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((sample-x1) / (x2-x1));
  // std::cout << "Waveshaper::interpolation - sample = " << sample << std::endl;
  // std::cout << "Waveshaper::interpolation - x1 = " <<x1 << std::endl;
  // std::cout << "Waveshaper::interpolation - x2 = " << x2 << std::endl;
  // std::cout << "Waveshaper::interpolation - y1 = " << y1 << std::endl;
  // std::cout << "Waveshaper::interpolation - y2 = " << y2 << std::endl;
  // std::cout << "Waveshaper::interpolation - y = " << y << std::endl;
  return y;
}

void PickSample::fillBuffer()
{
  int channel = 0;
  audioFile.setBitDepth (8);
  for(int i = 0; i < numSamples; i++)
  {
    float currentSample = audioFile.samples[channel][i];
    // currentSample += 1;
    // float b = scale(currentSample,0,2,0,numSamples);
    std::cout << "PickSample::fillBuffer - currentSample = " << currentSample << std::fixed << "\n";
    buffer[i] = currentSample;
  }
}

float PickSample::calculateL(float sample)
{
  return 0;
}

float PickSample::calculateR(float sample)
{
  return 0;
}
