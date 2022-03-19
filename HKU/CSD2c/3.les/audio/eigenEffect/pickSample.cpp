#include "pickSample.h"
AudioFile<double> audioFile;

PickSample::PickSample()
{
  std::cout << "PickSample - Constructor " << std::endl;
  audioFile.load ("../eigenEffect/samples/OH.wav");
  numSamples = audioFile.getNumSamplesPerChannel();
  bufSize = numSamples;
  audioFile.printSummary();
  buffer = new float[bufSize];
  std::cout << "PickSample::Constructor - bufSize = " << bufSize << std::endl;
  fillBuffer();
}

PickSample::~PickSample()
{
  std::cout << "PickSample - Destructor " << std::endl;
}

float PickSample::calculateM(float sample)
{
  sample += 1;
  float s = scale(sample,0,2.1,0,numSamples);
  return s;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  //scale sample to buffersize so [0,numSamples
  float xFromDistance = x2From - x1From;
  float sampleScaled = sample/xFromDistance;
  float xToDistance = x2To - x1To;
  float x = (sampleScaled * xToDistance) + x1To;
  return x;
}

void PickSample::fillBuffer()
{
  int channel = 0;
  WriteToFile writeFile("output.csv",true);
  for(int i = 0; i < numSamples; i++)
  {
    double currentSample = audioFile.samples[channel][i];
    writeFile.write(std::to_string(currentSample )+ "\n");
    buffer[i] = currentSample;
  }
}
