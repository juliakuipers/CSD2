#include "pickSample.h"
AudioFile<double> audioFile;

PickSample::PickSample() : numSamples(audioFile.getNumSamplesPerChannel()), bufSize(numSamples)
{
  std::cout << "PickSample - Constructor " << std::endl;
  audioFile.load ("../eigenEffect/samples/OH.wav");
  audioFile.printSummary();
  buffer = new float[bufSize];
  fillBuffer();
}

PickSample::~PickSample()
{
  std::cout << "PickSample - Destructor " << std::endl;
}

float PickSample::calculateM(float sample)
{
  sample += 1;
  //sample goes from [-1,1]
  //sample += 1 so [0,2]
  float s = scale(sample,0,2.1,0,numSamples);
  return s;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  //scale sample to buffersize so [0,numSamples]
  float xFromDistance = x2From - x1From;
  float sampleScaled = sample/xFromDistance;
  float xToDistance = x2To - x1To;
  float x = (sampleScaled * xToDistance) + x1To;
  std::cout << "PickSample::scale - x = " << x << std::endl;
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
