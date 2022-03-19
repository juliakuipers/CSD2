#include "pickSample.h"
AudioFile<float> audioFile;

PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  v.clear();
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
  v.clear();
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
  // cout << "PickSample::scale - sample =" << sample <<"\n ";
  float xFromDistance = x2From - x1From;
  // cout << "PickSample::scale - xFromDistance =" << xFromDistance <<"\n ";
  float sampleScaled = sample/xFromDistance;
  // cout << "PickSample::scale - sampleScaled =" << sampleScaled <<"\n ";
  float xToDistance = x2To - x1To;
  // cout << "PickSample::scale - xToDistance =" << xToDistance <<"\n ";
  float x = (sampleScaled * xToDistance) + x1To;
  // cout << "PickSample::scale - x =" << x <<"\n \n";
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
    cout << "PickSample::fillBuffer - currentSample = " << currentSample <<"\n ";
    //currentSample is not right, somewhere while retrieving it something goes wrong
    cout << "PickSample::fillBuffer - channel = " << channel <<"\n ";
    cout << "PickSample::fillBuffer - i = " << i <<"\n \n ";

    if(currentSample > 9.97782e-05 || currentSample < -9.95398e-05) {v.push_back(currentSample);}
    // wtf->write(std::to_string(currentSample) + "\n");
  }
  sort(v.begin(), v.end());
  float begin = *v.begin();
  float back = v.back();
  for (auto j = v.begin(); j != v.end(); ++j)
  {
    v.erase(v.begin());
    // cout << "PickSample::fillBuffer - begin =" << begin <<"\n ";
    // cout << "PickSample::fillBuffer - back = " << back <<"\n";
    // cout << "PickSample::fillBuffer - v.i* =" << *i <<"\n \n ";
    v.push_back(scale(*j, begin, back, -1, 1));
    wtf->write(std::to_string(*j) + "\n");
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
