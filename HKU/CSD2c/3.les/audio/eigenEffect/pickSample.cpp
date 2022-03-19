#include "pickSample.h"
AudioFile<float> audioFile;
using namespace std;

PickSample::PickSample(float freq, float samplerate) : Effect(freq,samplerate)
{
  audioFile.load ("../3.les/audio/eigenEffect/samples/VOX.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
  numSamples = 80000;
  bufSize = numSamples;
  buffer = new float[bufSize];
  fillBuffer();
  // cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
}

PickSample::~PickSample()
{}

float PickSample::calculateM(float sample)
{
  // cout << "PickSample::calculateM - sample =  = " << sample << endl;
  sample += 1;
  // cout << "PickSample::calculateM - sample +=1 =  = " << sample << endl;
  // std::cout << "PickSample::calculateM - numSamples =  = " << numSamples << endl;
  float s = scale(sample,0,2.1,0,numSamples);
  // cout << "PickSample::calculateM - s =  = " << s << endl;
  int intS = (int) s;
  // cout << "PickSample::calculateM - intS =  = " << intS << endl;
  float y = interpolate(s,intS,intS+1,buffer[intS],buffer[intS+1]);
  // cout << "PickSample::calculateM - buffer[intS] and buffer[intS+1] = " << buffer[intS] << " and " << buffer[intS+1] << endl;
  // cout << "PickSample::calculateM - y =  = " << y << endl;
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
  // cout << "Waveshaper::interpolation - sample = " << sample << endl;
  // cout << "Waveshaper::interpolation - x1 = " <<x1 << endl;
  // cout << "Waveshaper::interpolation - x2 = " << x2 << endl;
  // cout << "Waveshaper::interpolation - y1 = " << y1 << endl;
  // cout << "Waveshaper::interpolation - y2 = " << y2 << endl;
  // cout << "Waveshaper::interpolation - y = " << y << endl;
  return y;
}

void PickSample::fillBuffer()
{
  int channel = 0;
  audioFile.setBitDepth(16);
  cout << "PickSample::fillBuffer - numSamples = " << numSamples <<endl;
  audioFile.setAudioBufferSize(1, numSamples);
  audioFile.printSummary();
  for(int i = 0; i < numSamples; i++)
  {
    float currentSample = audioFile.samples[channel][i];
    // cout << "PickSample::fillBuffer - currentSample = " << currentSample << fixed << "\n";
    buffer[i] = currentSample;
  }
  sort(buffer,buffer+numSamples);
}

float PickSample::calculateL(float sample)
{
  return 0;
}

float PickSample::calculateR(float sample)
{
  return 0;
}
