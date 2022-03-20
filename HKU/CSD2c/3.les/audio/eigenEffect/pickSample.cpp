#include "pickSample.h"
AudioFile<float> audioFile;

PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  v.clear();
  // audioFile.load ("../3.les/audio/eigenEffect/samples/PAD.wav");
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
  float s = scale(sample,0,2.1,0,v.size());
  int intS = (int) s;
  float y = interpolate(s,intS,intS+1,v[intS],v[intS+1]);
  cout << "PickSample::calculateM - y =" << y <<"\n ";
  return y;
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
  audioFile.load ("../eigenEffect/samples/OH.wav");
  audioFile.printSummary();
  numSamples = audioFile.getNumSamplesPerChannel();
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
  numSamples -= 1;
  int channel = 0;
  audioFile.setBitDepth(24);
  // cout << "PickSample::fillBuffer - numSamples = " << numSamples <<endl;
  audioFile.printSummary();
  for(int i = 0; i < numSamples; i++)
  {
    float currentSample = audioFile.samples[channel][i];
    if(currentSample > 0.009 || currentSample < 0.009) {v.push_back(currentSample);}
    // cout << "PickSample::fillBuffer - currentSample =" << currentSample <<"\n ";
    // wtf->write(std::to_string(currentSample) + "\n");
  }

  sort(v.begin(), v.end());
  float front = v.front();
  float back = v.back();
  // for (auto j = v.end(); j != v.begin(); --j)
  //so v.end() points to the iterator after the end of the vector
  for (auto j = v.begin(); j != v.end(); ++j)
  {
    v.erase(v.begin());
    // float begin = *v.begin();
    // float end = *v.end();
    // cout << "PickSample::fillBuffer - end & begin =" << end << " & " << begin <<"\n ";
    // cout << "PickSample::fillBuffer - begin =" << begin <<"\n ";
    // cout << "PickSample::fillBuffer - j =" << j <<"\n ";
    // cout << "PickSample::fillBuffer - back = " << back <<"\n";
    // cout << "PickSample::fillBuffer - v.i* =" << *i <<"\n \n ";
    // cout << "PickSample::fillBuffer - v.j* =" << *j <<"\n \n ";
    // v.push_back(scale(*j, front, back, -1, 1));
    float s = scale(*j, front, back, -1, 1);
    // if(s<1 || s> -1) {v.push_back(s);}
    // cout << "PickSample::fillBuffer - s =" << s <<"\n \n ";
    // v.push_back(*j);
    // cout << "PickSample::fillBuffer - v.j* =" << *j <<"\n \n ";
    // wtf->write(std::to_string(s) + "\n");
  }
  cout << "PickSample::fillBuffer - v.size() = " << v.size() << endl;

  // for(int j = 0; )

}

float PickSample::calculateL(float sample)
{
  return 0;
}

float PickSample::calculateR(float sample)
{
  return 0;
}
