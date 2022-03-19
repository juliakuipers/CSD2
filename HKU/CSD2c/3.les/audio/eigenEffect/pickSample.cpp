#include "pickSample.h"
AudioFile<float> audioFile;
using namespace std;

PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  // audioFile.load ("../3.les/audio/eigenEffect/samples/PAD.wav");
  audioFile.load ("../eigenEffect/samples/CLAP.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
  numSamples -= 1;
  bufSize = numSamples;
  buffer = new float[bufSize];
  fillBuffer();
}

PickSample::~PickSample()
{
  delete wtf;
  wtf = nullptr;
}

float PickSample::calculateM(float sample)
{
  sample += 1;
  float s = scale(sample,0,2.1,0,numSamples);
  int intS = (int) s;
  float y = interpolate(s,intS,intS+1,buffer[intS],buffer[intS+1]);
  return y;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  float xFromDistance = x2From - x1From;
  // cout << "PickSample::scale - xFromDistance = " << xFromDistance << endl;
  float sampleScaled = sample/xFromDistance;
  // cout << "PickSample::scale - sampleScaled = " << sampleScaled << endl;
  // cout << "PickSample::scale - x1To = " << x1To << endl;
  // cout << "PickSample::scale - x2To = " << x2To << endl;
  float xToDistance = x2To - x1To;
  // cout << "PickSample::scale - xToDistance = " << xToDistance << endl;
  float x = (sampleScaled * xToDistance) + x1To;
  // cout << "PickSample::scale - x = " << x << endl;
  return x;
}

float PickSample::interpolate(float sample, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((sample-x1) / (x2-x1));
  return y;
}

void PickSample::fillBuffer()
{
  int channel = 0;
  audioFile.setBitDepth(24);
  cout << "PickSample::fillBuffer - numSamples = " << numSamples <<endl;
  audioFile.printSummary();
  for(int i = 0; i < numSamples; i++)
  {
    float currentSample = audioFile.samples[channel][i];
    if(currentSample != 0.0) {cout << "currentSample != 0 - value = " << currentSample << fixed << endl;}
    // wtf->write(std::to_string(currentSample) + "\n");
    buffer[i] = currentSample;
  }
  sort(buffer,buffer+numSamples);
  for(int i = 0; i < numSamples; i++)
  {
    // cout << "PickSample::fillBuffer - buffer[i] = " << buffer[i] << fixed << "\n";
    wtf->write(std::to_string(buffer[i]) + "\n");
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

//first i should know how many times 0 is in the sample
//i could make 2 buffers
//i'm not sure if i can resize the buffer
