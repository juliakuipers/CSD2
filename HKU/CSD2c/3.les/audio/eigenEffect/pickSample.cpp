#include "pickSample.h"
AudioFile<float> audioFile;

PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  // audioFile.load ("../3.les/audio/eigenEffect/samples/PAD.wav");
  audioFile.load ("../eigenEffect/samples/OH.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
  numSamples -= 1;
  // bufSize = numSamples;
  // buffer = new float[bufSize];
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
  // float y = interpolate(s,intS,intS+1,buffer[intS],buffer[intS+1]);
  return s;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  float xFromDistance = x2From - x1From;
  float sampleScaled = sample/xFromDistance;
  float xToDistance = x2To - x1To;
  float x = (sampleScaled * xToDistance) + x1To;
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
  // cout << "PickSample::fillBuffer - numSamples = " << numSamples <<endl;
  audioFile.printSummary();
  for(int i = 0; i < numSamples; i++)
  {
    float currentSample = audioFile.samples[channel][i];
    if(currentSample > 9.97782e-05 || currentSample < -9.95398e-05) {v.push_back(currentSample);}
    // wtf->write(std::to_string(currentSample) + "\n");
    // buffer[i] = currentSample;
  }
  // sort(buffer,buffer+numSamples);
  sort(v.begin(), v.end());
  // for(int i = 0; i < numSamples; i++)
  // {
  //   // cout << "PickSample::fillBuffer - buffer[i] = " << buffer[i] << fixed << "\n";
  //   wtf->write(std::to_string(buffer[i]) + "\n");
  // }
  float begin = *v.begin();
  float end = *v.end();
  // float end = *v.end();
  for (auto i = v.begin(); i != v.end(); ++i)
  {
    cout << "PickSample::fillBuffer - v.i* =" << *i <<"\n ";
    v.erase(v.begin());
    cout << "PickSample::fillBuffer - begin =" << begin <<"\n ";
    cout << "PickSample::fillBuffer - end = " << end <<"\n \n";
    v.push_back(scale(*i, begin, end, -1, 1));
    wtf->write(std::to_string(*i) + "\n");
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
